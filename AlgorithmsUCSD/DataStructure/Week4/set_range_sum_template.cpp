#include <cstddef>
#include <iostream>


typedef long long ll;
struct vertex{
    int key;
    ll sum;
    vertex* left;
    vertex* right;
    vertex* parent;
    
    vertex(int key, ll sum, vertex* left, vertex* right, vertex* parent):
    key(key), sum(sum), left(left), right(right), parent(parent){}
};

ll GetSum(vertex* v){
    if(v==NULL)
        return 0ll;
    return v->sum;
}

void update(vertex* v){
    if(v==NULL) return;
    v->sum = v->key + GetSum(v->left) + GetSum(v->right);
    if(v->left != NULL)
        v->left->parent = v;
    if(v->right != NULL)
        v->right->parent = v;
}

void smallRotate(vertex *&v){
    vertex* parent = v->parent;
    if(parent==NULL)
        return;
    vertex* grandparent = v->parent->parent;
    if(parent->left == v){
        //zig
        vertex* m = v->right;
        v->right = parent;
        parent->left = m;
    }
    else{
        //zag
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
        //zig-zig
        smallRotate(v->parent);
        smallRotate(v);
    }
    else if(v->parent->right==v && v->parent->parent->right==v->parent){
        //zag-zag
        smallRotate(v->parent);
        smallRotate(v);
    }
    else{
        //zig-zag or zag-zig
        smallRotate(v);
        smallRotate(v);
    }
}

void splay(vertex *&root, vertex* v){
    if(v==NULL) return;
    while(v->parent != NULL){
        if(v->parent->parent == NULL){
            smallRotate(v);
            break;
        }
        bigRotate(v);
    }
    root = v;
}

vertex* find(vertex*& root, int key){
    vertex* v = root;
    vertex* last = root;
    vertex* next = NULL;
    while(v!=NULL){
        //next: returns the pointer or smallest bigger node if not found
        if(v->key >= key && (next==NULL||v->key < next->key)){
            next = v;
        }
        last = v;
        if(v->key == key)
            break;
        if(v->key < key)
            v = v->right;
        else
            v = v->left;
    }
    splay(root, last);
    //last and next may be different
    return next;
}



void split(vertex* root, int key, vertex*& left, vertex*& right){
    right = find(root, key);
    splay(root, right);
    //equal goes to right subtree
    if(right==NULL){
        //key is the largest item
        left = root;
        return;
    }
    left = right->left;
    right->left = NULL;
    if(left!=NULL)
        left->parent = NULL;
    update(left);
    update(right);
}

vertex* merge(vertex* left, vertex* right){
    if(left==NULL) return right;
    if(right==NULL) return left;
    vertex* min_right = right;
    while(min_right->left != NULL)
        min_right = min_right->left;
    splay(right, min_right);
    right->left = left;
    update(right);
    return right;
}

vertex* root = NULL;
void insert(int x){
    vertex* left = NULL;
    vertex* right = NULL;
    vertex* new_vertex = NULL;
    split(root, x, left, right);
    if(right==NULL || right->key!=x){
        //new node not found in tree, need to insert
        new_vertex = new vertex(x, x, NULL, NULL, NULL);
    }
    root = merge(merge(left, new_vertex), right);
}

void erase(int x){
    vertex *v = find(root, x);
    //splay(root, v);
    
    if(v==nullptr || v->key!=x)
        return; //not found
    
    if(v && v->key==x){
        root = merge(root->left, root->right);
        if(root)
            root->parent = nullptr;
    }
}


bool Find(int x){
    vertex* v = find(root, x);
    //splay(root, v);
    
    if(v==nullptr || v->key!=x)
        return false;
    
    if(v->key == x)
        return true;
    
    return false;
}

ll sum(int from, int to){
    vertex* left = NULL;
    vertex* right = NULL;
    vertex* middle = NULL;
    split(root, from, left, middle);
    //to+1 so that to is included in middle tree
    split(middle, to+1, middle, right);
    ll ans = 0;
    update(left);
    update(right);
    update(middle);
    if(middle!=nullptr)
        ans = middle->sum;
    root = merge(merge(left, middle), right);
    return ans;
}

const int MODULO = 1000000001;

int main(){
    int n;
    scanf("%d", &n);
    int last_sum_result = 0;
    for(int i=0; i<n; i++){
        char buffer[10];
        scanf("%s", buffer);
        char type=buffer[0];
        switch (type){
            case '+':{
                int x;
                scanf("%d", &x);
                insert((x+last_sum_result)%MODULO);
                break;
            }
            case '-':{
                int x;
                scanf("%d", &x);
                erase((x+last_sum_result)%MODULO);
                break;
            }
            case '?':{
                int x;
                scanf("%d", &x);
                printf(Find((x+last_sum_result)%MODULO) ? "Found\n" : "Not found\n");
                break;
            }
            case 's':{
                int l, r;
                scanf("%d %d", &l, &r);
                ll res = sum((l+last_sum_result)%MODULO, (r+last_sum_result)%MODULO);
                printf("%lld\n", res);
                last_sum_result = int(res%MODULO);
            }
        }
    }
    return 0;
}

//15
//? 1
//+ 1
//? 1
//+ 2
//s 1 2
//+ 1000000000
//? 1000000000
//- 1000000000
//? 1000000000
//s 999999999 1000000000
//- 2
//? 2
//- 0
//+ 9
//s 0 9









