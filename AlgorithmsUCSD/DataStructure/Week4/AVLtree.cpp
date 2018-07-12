#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;

struct AVLTreeNode{
    int val;
    int height;
    AVLTreeNode *Left;
    AVLTreeNode *Right;
};

int GetHeight(AVLTreeNode *treeNode){
    return treeNode==NULL ? -1 : treeNode->height;
    
    //without maintaining height:
    // if(treeNode==NULL)
    // 	return -1;
    // return 1+max(GetHeight(treeNode->Left), GetHeight(treeNode->Right));
}

void LL_rotate(AVLTreeNode *&treeNode){
    AVLTreeNode *temp = treeNode->Left;
    treeNode->Left = temp->Right;
    temp->Right = treeNode;
    treeNode->height = max(GetHeight(treeNode->Left), GetHeight(treeNode->Right))+1;
    temp->height = max(GetHeight(temp->Left), treeNode->height)+1;
    treeNode = temp;
}

void RR_rotate(AVLTreeNode *&treeNode){
    AVLTreeNode *temp = treeNode->Right;
    treeNode->Right = temp->Left;
    temp->Left = treeNode;
    treeNode->height = max(GetHeight(treeNode->Left), GetHeight(treeNode->Right))+1;
    temp->height = max(treeNode->height, GetHeight(temp->Right))+1;
    treeNode = temp;
}

void LR_rotate(AVLTreeNode *&treeNode){
    RR_rotate(treeNode->Left);
    LL_rotate(treeNode);
}

void RL_rotate(AVLTreeNode *&treeNode){
    LL_rotate(treeNode->Right);
    RR_rotate(treeNode);
}

AVLTreeNode* FindMin(AVLTreeNode *treeNode){
    if(treeNode == NULL)
        return NULL;
    else if(treeNode->Left==NULL)
        return treeNode;
    else
        return FindMin(treeNode->Left);
}

AVLTreeNode* FindMax(AVLTreeNode *treeNode){
    if(treeNode==NULL)
        return NULL;
    else if(treeNode->Right==NULL)
        return treeNode;
    else
        return FindMax(treeNode->Right);
}

void Insert(AVLTreeNode *&treeNode, int data){
    if(treeNode==NULL){
        treeNode = new AVLTreeNode;
        treeNode->Left = NULL;
        treeNode->Right = NULL;
        treeNode->val = data;
    }
    else if(treeNode->val > data){
        //go to left subtree
        Insert(treeNode->Left, data);
        //the max height diff is 2
        if(GetHeight(treeNode->Left) - GetHeight(treeNode->Right)>1){
            if(data < treeNode->Left->val)
                LL_rotate(treeNode);
            else
                LR_rotate(treeNode);
        }
    }
    else if(treeNode->val < data){
        //go to right subtree
        Insert(treeNode->Right, data);
        if(GetHeight(treeNode->Right) - GetHeight(treeNode->Left)>1){
            if(data > treeNode->Right->val)
                RR_rotate(treeNode);
            else
                RL_rotate(treeNode);
        }
    }
    treeNode->height = max(GetHeight(treeNode->Left), GetHeight(treeNode->Right))+1;
}

void Remove(AVLTreeNode *&treeNode, int data){
    if(treeNode==NULL) //not found
        return;
    if(treeNode->val > data){
        //go to left subtree
        Remove(treeNode->Left, data);
        if(GetHeight(treeNode->Right) - GetHeight(treeNode->Left)>1){
            if(GetHeight(treeNode->Right->Left)>GetHeight(treeNode->Right->Right))
                RL_rotate(treeNode);
            else
                //same height also use RR
                RR_rotate(treeNode);
        }
    }
    else if(treeNode->val < data){
        //go to right subtree
        Remove(treeNode->Right, data);
        if(GetHeight(treeNode->Left)-GetHeight(treeNode->Right)>1){
            if(GetHeight(treeNode->Left->Right)>GetHeight(treeNode->Left->Left))
                LR_rotate(treeNode);
            else
                //same height also use LL
                LL_rotate(treeNode);
        }
    }
    else if(treeNode->Left!=NULL &&treeNode->Right!=NULL){
        //found, has two children
        treeNode->val = FindMin(treeNode->Right)->val;
        //can replace with either predecessor or successor
        Remove(treeNode->Right, treeNode->val); //not 'data'!
        if(GetHeight(treeNode->Left)-GetHeight(treeNode->Right)>1){
            if(GetHeight(treeNode->Left->Right)>GetHeight(treeNode->Left->Left))
                LR_rotate(treeNode);
            else
                LL_rotate(treeNode);
        }
    }
    else{
        //found, has one or no child
        AVLTreeNode *temp = treeNode;
        treeNode = (treeNode->Left!=NULL) ? treeNode->Left : treeNode->Right;
        delete temp;
        temp = NULL;
    }
    
    //treeNode==NULL means that the node is a leaf,
    if(treeNode != NULL)
        treeNode->height = max(GetHeight(treeNode->Left), GetHeight(treeNode->Right))+1;
}

void LevelOrderTraverse(AVLTreeNode *root){
    if(root==NULL) return;
    
    queue<AVLTreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        AVLTreeNode *p = Q.front();
        if(p->Left!=NULL)
            Q.push(p->Left);
        if(p->Right!=NULL)
            Q.push(p->Right);
        cout<<p->val<<'('<<p->height<<") ";
        Q.pop();
    }
    cout<<"\n";
}

void preOrderTraverse(AVLTreeNode *treeNode){
    if(treeNode != NULL){
        cout<<treeNode->val<<'('<<treeNode->height<<") ";
        preOrderTraverse(treeNode->Left);
        preOrderTraverse(treeNode->Right);
    }
}

void inOrderTraverse(AVLTreeNode *treeNode){
    if(treeNode!=NULL){
        inOrderTraverse(treeNode->Left);
        cout<<treeNode->val<<'('<<treeNode->height<<") ";
        inOrderTraverse(treeNode->Right);
    }
}

void postOrderTraverse(AVLTreeNode *&treeNode){
    if(treeNode != NULL){
        postOrderTraverse(treeNode->Left);
        postOrderTraverse(treeNode->Right);
        cout<<treeNode->val<<'('<<treeNode->height<<") ";
    }
}

void MakeEmpty(AVLTreeNode *&treeNode){
    if(treeNode!=NULL){
        MakeEmpty(treeNode->Left);
        MakeEmpty(treeNode->Right);
        delete treeNode;
    }
    treeNode = NULL;
}

void BuildAVLTree(AVLTreeNode *&root, int a[], int n){
    for(int i=0; i<n; i++){
        Insert(root, a[i]);
    }
}





//the max height diff is 2
//only balance this current node,
//do not recursively go up
void balance(AVLTreeNode *&treeNode){
    if(treeNode==NULL)
        return;
    if(GetHeight(treeNode->Left)-GetHeight(treeNode->Right)>1){
        if(GetHeight(treeNode->Left->Right)>GetHeight(treeNode->Left->Left))
            LR_rotate(treeNode);
        else
            LL_rotate(treeNode);
    }
    if(GetHeight(treeNode->Right)-GetHeight(treeNode->Left)>1){
        if(GetHeight(treeNode->Right->Left)>GetHeight(treeNode->Right->Right))
            RL_rotate(treeNode);
        else
            RR_rotate(treeNode);
    }
    treeNode->height = max(GetHeight(treeNode->Left), GetHeight(treeNode->Right))+1;
}


AVLTreeNode* MergeWithRoot(AVLTreeNode* R1, AVLTreeNode* R2, AVLTreeNode *&T){
    //abs needs <cstdlib>
    //R1: smaller tree, R2: bigger tree
    if(abs(GetHeight(R1)-GetHeight(R2))<=1){
        T->Left = R1;
        T->Right = R2;
        T->height = max(GetHeight(R1), GetHeight(R2))+1;
        return T;
    }
    else if(GetHeight(R1)>GetHeight(R2)){
        AVLTreeNode* newR = MergeWithRoot(R1->Right, R2, T);
        R1->Right = newR;
        balance(R1);
        return R1;
    }
    else{
        AVLTreeNode* newR = MergeWithRoot(R1, R2->Left, T);
        R2->Left = newR;
        balance(R2);
        return R2;
    }
}


AVLTreeNode* Merge(AVLTreeNode* R1, AVLTreeNode* R2){
    AVLTreeNode* T = FindMax(R1);
    AVLTreeNode* newRoot = new AVLTreeNode;
    newRoot->val = T->val;
    Remove(R1, T->val);
    MergeWithRoot(R1, R2, newRoot);
    return newRoot;
}


void split(AVLTreeNode *R, int val, AVLTreeNode *&small, AVLTreeNode *&big){
    if(R==NULL){
        small = NULL;
        big = NULL;
    }
    else if(val < R->val){
        split(R->Left, val, small, big);
        big = MergeWithRoot(big, R->Right, R);
    }
    else{
        //I put equal here as well, so equal will go to small tree
        split(R->Right, val, small, big);
        small = MergeWithRoot(R->Left, small, R);
    }
}

int main(){
    int a[] = {3,2,4,5,6,7,16,15,14,13,12,11,10,8,9};//test insert
    
    AVLTreeNode* root = NULL, *small=NULL, *big=NULL;
    BuildAVLTree(root, a, sizeof(a)/sizeof(a[0]));
    LevelOrderTraverse(root);
    
    split(root, 7, small, big);
    LevelOrderTraverse(small);
    cout<<endl;
    LevelOrderTraverse(big);
    
    root = Merge(small, big);
    LevelOrderTraverse(root);
    return 0;
}