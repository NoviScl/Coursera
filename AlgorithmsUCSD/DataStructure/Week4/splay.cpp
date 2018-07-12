#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

struct STnode{
    int key;
    STnode *left, *right;
};

STnode* newNode(int key){
    STnode* node = new STnode;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

//make left the new root
STnode* rightRotate(STnode* node){
    STnode* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}


//make right the new root
STnode* leftRotate(STnode* node){
    STnode *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
}


//geekforgeeks have a great explanation of this
//it brings the key to root if found
//brings the last accessed node to root if not found
//modifies the tree and returns the new root
STnode* splay(STnode* root, int key){
    if(root==NULL || root->key==key)
        return root;
    
    //go to left subtree
    //this parts deals with zig, zig-zig, zig-zag
    if(root->key > key){
        //key not in tree, done
        if(root->left==NULL) return root;
        
        //zig-zig (left left)
        if(root->left->key > key){
            //first recursively bring the key as root of left-left
            root->left->left = splay(root->left->left, key);
            //do first rotation for root, second rotation is done after else
            root = rightRotate(root);
        }
        //zig-zag (left right)
        else if(root->left->key < key){
            //first recursively bring the key as root of left-right
            root->left->right = splay(root->left->right, key);
            
            //do first rotation for root->left
            //the new root can't be NULL
            if(root->left->right!=NULL)
                root->left = leftRotate(root->left);
        }
        //do second rotation for root (or one rotation for zig)
        //root->left might be NULL in zig-zig and key not found
        return (root->left==NULL) ? root: rightRotate(root);
    }
    //go to right subtree
    else{
        //key not in tree, done
        if(root->right == NULL) return root;
        
        //zag-zig (right left)
        if(root->right->key > key){
            //bring the key as root of right-left
            root->right->left = splay(root->right->left, key);
            
            //do first rotation for root->right
            if(root->right->left!=NULL)
                root->right = rightRotate(root->right);
        }
        //zag-zag (right right)
        else if(root->right->key < key){
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        
        //do second rotation or the only rotation for zag
        //root->right might be NULL if zag-zag and key not found
        return (root->right==NULL) ? root: leftRotate(root);
    }
}

//if found, make key the new root and return
//else use the last accessed node instead
STnode* search(STnode* root, int key){
    return splay(root, key);
}

void preOrder(STnode* root){
    if(root != NULL){
        cout<<root->key<<' ';
        preOrder(root->left);
        preOrder(root->right);
    }
}

STnode* insert(STnode* root, int k){
    if(root==NULL) return newNode(k);
    
    //brings the closest leaf node to root
    root = splay(root, k);
    
    //key already present, just return
    if(root->key == k) return root;
    
    STnode* newnode = newNode(k);
    
    if(root->key > k){
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }
    else{
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }
    
    return newnode;
}


//returns the new root after removing key
STnode* delete_key(STnode* root, int key){
    STnode* temp;
    if(!root)
        return NULL;
    
    root = splay(root, key);
    
    //key not in tree
    if(key != root->key)
        return root;
    
    if(!root->left){
        temp = root;
        root = root->right;
    }
    else{
        temp = root;
        /*Note: Since key == root->key,
         so after Splay(key, root->lchild),
         the tree we get will have no right child tree
         because the largest node in left subtree becomes the root,
         there is no node larger than the root in left subtree
         and maximum node in left subtree will get splayed*/
        // New root
        root = splay(root->left, key);
        root->right = temp->right;
    }
    
    delete temp;
    return root;
}


void split(STnode *root, STnode *&small, STnode *&big, int key){
    if(!root) return;
    root = search(root, key);
    if(root->key > key){
        small = root->left;
        root->left = NULL;
        big = root;
    }
    else if(root->key < key){
        big = root->right;
        root->right = NULL;
        small = root;
    }
    else{
        small = root->left;
        big = root->right;
    }
}

const int MAX = 9999999;
STnode* merge(STnode *R1, STnode *R2){
    //assume R1 is the root of the small tree
    R1 = search(R1, MAX); //splay the largest item of R1
    R1->right = R2;
    return R1;
}


int main(){
    STnode* root = newNode(100);
    root = insert(root, 50);
    root = insert(root, 120);
    root = insert(root, 30);
    root = delete_key(root, 100);
    preOrder(root);
}


