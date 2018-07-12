#include <iostream>
#include <cstdlib>
using namespace std;

typedef long long ll;
struct node{
    ll key, sum;
    node *left = NULL, *right = NULL;
};

node* newNode(ll key){
    node* newnode = new node;
    newnode->key = key;
    newnode->sum = key;
    return newnode;
}

ll x = 0;
const ll M = 1000000001;

ll GetSum(node *tree){
    if(!tree)
        return 0;
    return tree->sum;
}

node* leftRotate(node *tree){
    //assume right child exists
    node* temp = tree->right;
    tree->right = temp->left;
    temp->left = tree;
    tree->sum = GetSum(tree->left)+GetSum(tree->right)+tree->key;
    temp->sum = GetSum(temp->left)+GetSum(temp->right)+temp->key;
    return temp;
}

node* rightRotate(node *tree){
    //assume left child exists
    node* temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    tree->sum = GetSum(tree->left)+GetSum(tree->right)+tree->key;
    temp->sum = GetSum(temp->left)+GetSum(temp->right)+temp->key;
    return temp;
}


node* splay(node *tree, ll key){
    if(tree==NULL || tree->key==key)
        return tree;
    
    if(tree->key < key){
        //right tree
        if(tree->right==NULL) return tree;
        
        if(key > tree->right->key){
            tree->right->right = splay(tree->right->right, key);
            tree = leftRotate(tree);
        }
        else if(key < tree->right->key){
            tree->right->left = splay(tree->right->left, key);
            if(tree->right->left!=NULL)
                tree->right = rightRotate(tree->right);
        }
        if(tree->right!=NULL)
            tree = leftRotate(tree);
        return tree;
    }
    else{
        if(tree->left==NULL) return tree;
        
        if(key > tree->left->key){
            tree->left->right = splay(tree->left->right, key);
            if(tree->left->right!=NULL)
                tree->left = leftRotate(tree->left);
        }
        else if(key < tree->left->key){
            tree->left->left = splay(tree->left->left, key);
            tree = rightRotate(tree);
        }
        
        if(tree->left!=NULL)
            tree = rightRotate(tree);
        return tree;
    }
}

node* insert(node* tree, ll key){
    if(tree==NULL)
        return newNode(key);
    
    tree = splay(tree, key);
    
    if(tree->key == key)
        return tree;
    
    node* root = newNode(key);
    
    if(key > tree->key){
        root->left = tree;
        root->right = tree->right;
        tree->right = NULL;
        tree->sum = GetSum(tree->left)+GetSum(tree->right)+tree->key;
    }
    else{
        root->right = tree;
        root->left = tree->left;
        tree->left = NULL;
    }
    
    tree->sum = GetSum(tree->left)+GetSum(tree->right)+tree->key;
    root->sum = GetSum(root->left)+GetSum(root->right)+root->key;
    return root;
}

node* remove(node* tree, ll key){
    if(tree==NULL) return NULL;
    
    tree = splay(tree, key);
    if(tree->key != key)
        return tree; //not found
    
    node *del = tree;
    if(!tree->left)
        tree = tree->right;
    else{
        tree = splay(tree->left, key);
        tree->right = del->right;
    }
    
    delete del;
    if(tree)
        tree->sum = GetSum(tree->left)+GetSum(tree->right)+tree->key;
    return tree;
}

bool find(node *&tree, ll key){
    if(tree==NULL) return false;
    
    tree = splay(tree, key);
    if(tree->key==key)
        return true;
    else
        return false;
}

ll update_sum(node *&tree){
    tree->sum = GetSum(tree->left)+GetSum(tree->right)+tree->key;
    return tree->sum;
}

// ll get_sum(node *tree, ll left, ll right){
//     node *middle;
//     if(!tree) return 0;
//     tree = splay(tree, left);
//     if(tree->key >= left){
//         //small = tree->left;
//         middle = tree;
//         middle->left = NULL;
//         middle->sum = GetSum(middle->left)+GetSum(middle->right)+middle->key;
//     }
//     else{
//         //small = tree;
//         middle = tree->right;
//         //small->right = NULL;
//         //small->sum = GetSum(small->left)+GetSum(small->right)+small->key;
//     }
    
//     if(middle == NULL) return 0;
//     middle = splay(middle, right);
//     if(middle->key > right){
//         //big = middle;
//         middle = middle->left;
//         //big->left = NULL;
//         //update_sum(big);
//         return GetSum(middle);
//     }
//     else{
//         //big = middle->right;
//         middle->right = NULL;
//         return update_sum(middle);
//     }
// }

void split(node* tree, node *&small, node *&big, ll key){
	if(tree==NULL) return;
	tree = splay(tree, key);
	if(tree->key < key){
		small = tree;
		big = tree->right;
		small->right = NULL;
		update_sum(small);
	}	
	else if(tree->key > key){
		small = tree->left;
		big = tree;
		big->left = NULL;
		update_sum(big);
	}
	else{
		//include equal in both subtrees
		small = tree;
		big = tree;
		small->right = NULL
		big->left = NULL;
	}
}

const ll MAX = 999999999;
node* merge(node* R1, node* R2){
	node* T = splay(R1, MAX);
	T->right = R2;
	return T;
}

ll get_sum(node* tree, ll left, ll right){
	node* small, *middle, *big;
	if(tree==NULL) return 0;
	split(tree, small, middle, left);
	split(middle, middle, big, right);
	return GetSum(middle);
}


int main(){
    ll n, num1, num2;
    char op;
    node* root = NULL;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>op;
        if(op=='?'){
            cin>>num1;
            if(find(root, (num1+x)%M))
                cout<<"Found"<<endl;
            else
                cout<<"Not found"<<endl;
        }
        else if(op=='+'){
            cin>>num1;
            root = insert(root, (num1+x)%M);
        }
        else if(op=='-'){
            cin>>num1;
            root = remove(root, (num1+x)%M);
        }
        else{
            cin>>num1>>num2;
            x = get_sum(root, (num1+x)%M, (num2+x)%M);
            cout<<x<<endl;
        }
    }
}





