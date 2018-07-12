#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;

struct vertex{
    char key;
    ll size; //no of nodes under it, including itself
    vertex* left;
    vertex* right;
    vertex* parent;
    
    vertex(char key, ll size, vertex* left, vertex* right, vertex* parent):
    key(key),
    size(size),
    left(left),
    right(right),
    parent(parent)
    {}
};

class rope{
    
public:
    string res;
    vertex* root;
    rope(const string &s){
        root = NULL;
        for(int i=0; i<s.length(); i++){
            vertex *next = new vertex(s[i], 1, NULL, NULL, NULL);
            root = merge(root, next);
        }
    }
    
    ll GetSize(vertex* v){
        if(v==NULL) return 0;
        return v->size;
    }
    
    void update(vertex *&v){
        if(v==NULL)
            return;
        v->size = 1+GetSize(v->left)+GetSize(v->right);
        if(v->left!=NULL)
            v->left->parent = v;
        if(v->right!=NULL)
            v->right->parent = v;
    }
    
    void smallRotate(vertex *&v){
        vertex* parent = v->parent;
        if(parent==NULL)
            return;
        vertex* grandparent = v->parent->parent;
        if(parent->left==v){
            vertex *m = v->right;
            v->right = parent;
            parent->left = m;
        }
        else{
            vertex* m = v->left;
            v->left = parent;
            parent->right = m;
        }
        update(parent);
        update(v);
        v->parent = grandparent;
        if(grandparent!=NULL){
            if(grandparent->left==parent)
                grandparent->left = v;
            else
                grandparent->right = v;
        }
    }
    
    void bigRotate(vertex *&v){
        if(v->parent->left==v && v->parent->parent->left==v->parent){
            smallRotate(v->parent);
            smallRotate(v);
        }
        else if(v->parent->right==v && v->parent->parent->right==v->parent){
            smallRotate(v->parent);
            smallRotate(v);
        }
        else{
            smallRotate(v);
            smallRotate(v);
        }
    }
    
    void splay(vertex *&root, vertex *v){
        if(v==NULL)
            return;
        while(v->parent!=NULL){
            if(v->parent->parent==NULL){
                smallRotate(v);
                break;
            }
            bigRotate(v);
        }
        root = v;
    }
    
    vertex* find(vertex *&root, int leftNum){
        vertex *v = root;
        while(v!=NULL){
            ll s = GetSize(v->left);
            if(leftNum == (s+1))
                break;
            else if(leftNum < (s+1))
                v = v->left;
            else if(leftNum > (s+1)){
                v = v->right;
                leftNum -= (s+1);
            }
        }
        //v will be NULL if not found
        //not found means leftNum is too large
        //in this qn, it's either NULL or found
        splay(root, v);
        return v;
    }
    
    void split(vertex* root, int key, vertex*& left, vertex*& right){
        right = find(root, key);
        //splay(root, right);
        if(right == NULL){
            left = root;
            return;
        }
        left = right->left;
        //equal included in right subtree
        right->left = NULL;
        if(left!=NULL)
            left->parent = NULL;
        update(left);
        update(right);
    }
    
    vertex* merge(vertex* left, vertex* right){
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        vertex* min_right = right;
        while(min_right->left!=NULL)
            min_right = min_right->left;
        splay(right, min_right);
        right->left = left;
        update(right);
        return right;
    }
    
    void insert(vertex*& root, int k, vertex*& subString){
        //k: insert pos
        vertex* left = NULL;
        vertex* right = NULL;
        split(root, k, left, right);
        //allows repeated items
        //subString can be a tree
        //as long as the values are btw left and right
        root = merge(merge(left, subString), right);
    }
    
    string traversal_in_order(vertex* root){
        string printS = "";
        if(root==NULL)
            return printS;
        stack<vertex*> S;
        vertex* p = root;
        
        while(p!=NULL){
            S.push(p);
            p = p->left;
        }
        
        while(!S.empty()){
            p = S.top();
            printS.push_back(p->key);
            S.pop();
            p = p->right;
            while(p!=NULL){
                S.push(p);
                p = p->left;
            }
        }
        return printS;
    }
    
    void process(int i, int j, int k){
        vertex* left = NULL;
        vertex* right = NULL;
        vertex* middle = NULL;
        split(root, i+1, left, middle);
        //j-i+1 + 1 because equal goes to right
        //j-i+2 will include right end in middle
        split(middle, j-i+2, middle, right);
        root = merge(left, right);
        insert(root, k+1, middle);
    }
    
    //idea: (order statistic)
    //initially it is a BST with position index as ordering value
    //any splay operation will not change BST property
    //so at any time the in order will always be the original string
    string result(){
        res = traversal_in_order(root);
        return res;
    }
    
    void preOrder(vertex* tree){
        if(tree==NULL) return;
        cout<<tree->key<<' ';
        preOrder(tree->left);
        preOrder(tree->right);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    rope R(s);
    int actions;
    cin>>actions;
    for(int action_index=0; action_index<actions; ++action_index){
        int i, j, k;
        cin>>i>>j>>k;
        R.process(i, j, k);
    }
    cout<<R.result()<<endl;
}


















