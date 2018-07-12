#include <iostream>
using namespace std;

typedef pair<int, int> p;

int main(){
	string buffer;
	cin>>buffer;

	p stack[100050];
	int top=-1;

	for(int i=0; i<buffer.length(); i++){
		if(buffer[i]=='(' || buffer[i]=='[' ||buffer[i]=='{'){
			top++;
			stack[top].second = buffer[i];
			stack[top].first = i;
		}
		else if(buffer[i]==')' && satck[top].second=='(')
			top--;
		else if(buffer[i]==']' && stack[top].second=='[')
			top--;
		else if(buffer[i]=='}' && satck[top].second=='{')
			top--;
		else if(buffer[i]==')' || buffer[i]==']' || buffer[i]=='}'){
			cout<<(i+1);
			return 0;
		}
	}
	if(top<0){
		cout<<"Success";
		return 0;
	}
	while(top>0)
		top--;
	cout<<(stack[top].first+1);
}



typedef pair<int, int> p;

int main(){
	string buffer;
	cin>>buffer;

	p stack[100050];
	int top=-1;

	for(int i=0; i<buffer.length(); i++){
		if(buffer[i]=='(' || buffer[i]=='[' || buffer[i]=='{'){
			top++;
			stack[top].second = buffer[i];
			stack[top].first = i;
		}
		else if(buffer[i]==')' && stack[top].second=='(')
			top--;
		else if(buffer[i]==']' && stack[top].second=='[')
			top--;
		else if(buffer[i]=='}' && stack[top].second=='{')
			top--;
		else if(buffer[i]==')' || buffer[i]==']' || buffer[i]=='}'){
			cout<<(i+1);
			return 0;
		}
	}
	if(top<0){
		cout<<"Success";
		return 0;
	}
	cout<<stack[0].first+1;
}


#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif 

using namespace std;

struct Node{
	vector<Node*> children;
	int height = 1;
};

void BFS(){
	ios_base::sync_with_stdio(0);

	int n, t;
	cin>>n;

	Node* nodes[100000], *head=NULL;
	for(int i=0; i<n; i++){
		nodes[i] = new Node;
	}
	for(int i=0; i<n; i++){
		cin>>t;
		if(t==-1){
			head = nodes[i];
		}
		else{
			nodes[t]->children.push_back(nodes[i]);
		}
	}

	Node* queue[100000];
	int top=0, tail=0, maxheight=0;
	queue[tail]=head;
	tail++;
	while(tail>top){
		Node* cur = queue[top];
		top++;
		for(int i=0; i<cur->children.size(); i++){
			cur->children[i]->height = cur->height+1;
			maxheight = cur->children[i]->height;
			queue[tail]=cur->children[i];
			tail++;
		}
	}
	cout<<maxheight;
}

int main(int argc, char **argv){
	BFS();
}


struct Node{
	vector<Node*> children;
	int height=1;
};

void BFS(){
	ios_base::sync_with_stdio(0);

	int n, t;
	cin>>n;

	Node *nodes[100000], *head=NULL;
	for(int i=0; i<n; i++){
		nodes[i] = new Node;
	}
	for(int i=0; i<n; i++){
		cin>>t;
		if(t==-1){
			head = nodes[i];
		}
		else{
			nodes[t]->children.push_back(nodes[i]);
		}
	}

	Node* queue[100000];
	int top=0, tail=0, maxheight=0;
	queue[tail]=head;
	tail++;
	while(tail>top){
		Node *cur=queue[top];
		top++;
		for(int i=0; i<cur->children.size(); i++){
			cur->children[i]->height = cur->height+1;
			maxheight = cur->children[i]->height;
			queue[tail]=cur->chidlren[i];
			tail++;
		}
	}
	cout<<maxheight;
}




const int MAX = 1000000;
int heap[MAX], n;
int c = 0;

typedef pair<int, int> p;
vector<p> V;

void siftdown(int pos){
	int min_node = pos;
	if(pos*2+1<n && heap[pos*2+1]<heap[min_node])
		min_node = pos*2 + 1;
	if(pos*2+2<n && heap[pos*2+2]<heap[min_node])
		min_node = pos*2 + 2;
	if(min_node != pos){
		V.push_back(p{pos, min_node});
		c++;
		swap(heap[min_node], heap[pos]);
		siftdown(min_node);
	}
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>heap[i];

	for(int i=(n-1-1)/2; i>=0; i--)
		siftdown(i);

	cout<<c<<endl;
	for(int i=0; i<V.size(); i++){
		cout<<V[i].first<<' '<<V[i].second<<endl;
	}
}





const int MAX = 10000000;
int heap[MAX], n;
int c=0;

typedef pair<int, int> p;
vector<p> V;

void siftdown(int pos){
	int min_node = pos;
	if(pos*2+1<n && heap[pos*2+1]<heap[min_node])
		min_node = pos*2 + 1;
	if(pos*2+2 < n && heap[pos*2+2]<heap[min_node])
		min_node = pos*2 + 2;
	if(min_node != pos){
		V.push_back(p{pos,min_node});
		c++;
		swap(heap[min_node], heap[pos]);
		siftdown(min_node);
	}
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>heap[i];
	}
	for(int i=(n-1-1)/2; i>=0; i--){
		siftdown(i);
	}
	cout<<c<<endl;
	for(int i=0; i<V.size(); i++){
		cout<<V[i].first<<' '<<V[i].second<<endl;
	}
}


 typedef long long ll;
 struct thread{
 	ll start_time=0, index;
 };

struct cmp{
	bool operator()(thread a, thread b){
		if(a.start_time==b.start_time)
			return a.index > b.index;
		return a.start_time > b.start_time;
	}
};

int main(){
	ll threads, tasks;
	cin>>threads>>tasks;
	ll t;
	priority_queue<thread, vector<thread>, cmp> pq;

	for(ll i=0; i<threads; i++){
		thread temp;
		temp.start_time = 0;
		temp.index = i;
		pq.push(temp);
	}

	for(ll i=0; i<tasks; i++){
		cin>>t;
		cout<<pq.top().index<<' '<<pq.top().start_time<<endl;
		thread tempp;
		tempp.index = pq.top().index;
		tempp.start_time = pq.top().statr_time+t;
		pq.pop();
		pq.push(tempp);
	}
}

#include <queue>
using namespace std;

typedef long long ll;
struct thread{
	ll start_time = 0, index;
};

struct cmp{
	operator()(thread a, thread b){
		if(a.start_time == b.start_time)
			return a.index > b.index;
		return a.start_time > b.start_time;
	}
};

int main(){
	ll threads, tasks;
	cin>>threads>>tasks;
	ll t;
	priority_queue<thread, vector<thread>, cmp> pq;

	for(ll i=0; i<threads; i++){
		thread temp;
		temp.start_time = 0;
		temp.index = i;
		pq.push(temp);
	}

	for(ll i=0; i<tasks; i++){
		cin>>t;
		cout<<pq.top().index<<' '<<pq.top().start_time<<endl;
		thread temp;
		temp.index = pq.top().idnex;
		temp.start_time = pq.top().start_time + t;
		pq.pop();
		pq.push(temp);
	}
}



//!!!the use of priority_queue cmp (opposite logic)
struct cmp{
	bool operator()(thread a, thread b){
		if(a.start_time == b.start_time)
			return a.index > b.index;
		return a.start_time > b.start_time;
	}
};

int main(){
	priority_queue<thread, vector<thread> , cmp> pq;
}


int MAX = 0;
const int INF = 10000000;
int n, m;
int father[INF], Rank[INF];

struct node{
	int num, total;
};

node Nodes[INF];

int find(int pos){
	if(father[pos]!=pos)
		father[pos] = find(father[pos]);
	return father[pos];
}

int find(int pos){
	if(father[pos]!= pos){
		father[pos] = find(father[pos]);
	}
	return father[pos];
}

void merge(int a, int b){
	int i_a = find(a);
	int i_b = find(b);
	if(i_a != i_b){
		if(Rank[i_a] > Rank[i_b])
			swap(i_a, i_b);
		father[i_a] = i_b;
		Rank[i_b] = max(Rank[i_b], Rank[i_a]+1);
		Nodes[i_b].total += Nodes[i_a].total;
		MAX = max(MAX, Nodes[i_b].total);
	}
}

void merge(int a, int b){
	int i_a = find(a);
	int i_b = find(b);
	if(i_a != i_b){
		if(Rank[i_a] > Rank[i_b])
			swap(i_a, i_b);
		father[i_a] = i_b;
		Nodes[i_b].total += Nodes[i_a].total;
		MAX = max(MAX, Nodes[i_b].total);
	}
}

int main(){
	cin>>n>>m;
	int a, b;
	for(int i=0; i<=n; i++){
		father[i] = i;
		Rank[i] = 0;
	}

	for(int i=1; i<=n; i++){
		cin>>Nodes[i].num;
		Nodes[i].total = Nodes[i].num;
		MAX = max(MAX, Nodes[i].num);
	}

	for(int i=0; i<m; i++){
		cin>>a>>b;
		merge(a, b);
		cout<<MAX<<endl;
	}
}


#include <iostream>
#include <algorithm>
using namespace std;


typedef int Type;

struct avl_node{
	Type data;
	avl_node *lchild, *rchild;
}*root;

class avlTree{
public:
	avlTree(){
		root = NULL;
	}

	~AVLTree(){
		delete_tree(root);
	}

	void delete_tree(avl_node *node){
		if(node->lchild!=NULL){
			delete_tree(node->lchild);
		}
		if(node->rchild!=NULL){
			delete_tree(node->rchild);
		}
		delete node;
		node=NULL;
	}

	void delete_tree(avl_node *node){
		if(node->lchild!=NULL)
			delete_tree(node->lchild);
		if(node->rchild!=NULL)
			delete_tree(node->rchild);
		delete node;
		node = NULL;
	}

	int height(avl_node *node){
		if(node==NULL) return 0;
		int left_h = height(node->lchild);
		int right_h = height(node->rchild);
		return max(left_h, right_h)+1;
	}

	int height(avl_node *node){
		if(node==NULL) return 0;
		int left_h = height(node->lchild);
		int right_h = height(node->rchild);
		return max(left_h, right_h)+1;
	}

	int diff(avl_node *node){
		int left_h = height(node->lchild);
		int right_h = height(node->rchild);
		return left_h - right_h;
	}

	avl_node* RR_rotation(avl_node* head){
		avl_node *temp = head->rchild;
		head->rchild = temp->lchild;
		temp->lchild = head;
		return temp;
	}

	avl_node* RR_rotation(avl_node* head){
		avl_node *temp = head->rchild;
		head->rchild = temp->lchild;
		temp->lchild = head;
		return temp;
	}

	avl_node* LL_rotation(avl_node* head){
		avl_node *temp=head->lchild;
		head->lchild=temp->rchild;
		temp->rchild=head;
		return temp;
	}

	avl_node* RR_rotation(avl_node* head){
		avl_node *temp=head->rchild;
		head->rchild=temp->lchild;
		temp->lchild=head;
		return temp;
	}

	avl_node* LLrotation(avl_node* head){
		avl_node* temp=head->lchild;
		head->lchild=temp->rchild;
		temp->rchild=head;
		return temp;
	}

	avl_node* RR_rotation(avl_node* head){
		avl_node* temp=head->rchild;
		head->rchild=temp->lchild;
		temp->lchild=head;
		return temp;
	}

	avl_node* LL_rotation(avl_node* head){
		avl_node *temp=head->lchild;
		head->lchild=temp->rchild;
		temp->rchild=head;
		return temp;
	}

	avl_node* LR_rotation(avl_node* head){
		head->lchild=RR_rotation(head->lchild);
		return LL_rotation(head);
	}

	avl_node* RL_rotation(avl_node* head){
		head->rchild=LL_rotation(head->rchild);
		return RR_rotation(head);
	}

	avl_node* balance(avl_node* head){
		int bal_factor=diff(head);
		if(bal_factor>1){
			if(diff(head->lchild)>0){
				head=LL_rotation(head);
			}
			else{
				head=LR_rotation(head);
			}
		}
		else if(bal_factor<-1){
			if(diff(head->rchild)>0){
				head=RL_rotation(head);
			}
			else{
				head=RR_rotation(head);
			}
		}
		return head;
	}

	avl_node* insert(avl_node* root, Type value){
		if(root==NULL){
			root=new avl_node;
			root->data = value;
			root->lchild=NULL;
			root->rchild=NULL;
			return root;
		}
		else if(value<root->data){
			root->lchild=insert(root->lchild);
			root=balance(root);
		}
		else if(value>root->data){
			root->rchild=insert(root->rchild);
			root=balance(root);
		}
		return root;
	}

	avl_node* insert(avl_node* root, Type value){
		if(root==NULL){
			root = new avl_node;
			root->data = value;
			root->lchild=NULL;
			root->rchild=NULL;
			return root;
		}
		else if(value < root->data){
			root->lchild = insert(root->lchild, value);
			root = balance(root);
		}
		else if(value > root->data){
			root->rchild = insert(root->rchild);
			root = balance(root);
		}
		return root;
	}

	void display(avl_node* cur, int level){
		if(cur!=NULL){
			display(cur->rchild, level+1);
			cout<<endl;
			if(cur==root){
				cout<<"Root->";
			}
			for(int i=1; i<level && cur!=root; i++){
				cout<<"   ";
			}
			cout<<cur->data;
			display(cur->lchild, level+1);
		}
	}

	void preorder(avl_node* cur){
		if(cur==NULL) return;
		cout<<cur->data<<" ";
		preorder(cur->lchild);
		preorder(cur->rchild);
	}

	void inorder(avl_ndoe *cur){
		if(node==NULL) return;
		inorder(cur->lchild);
		cout<<cur->data;
		inorder(cur->rchild);
	}

	void postorder(avl_ndoe *cur){
		if(node==NULL) return;
		postorder(cur->lchild);
		postorder(cur->rchild);
		cout<<cur->data<<endl;
	}
};




struct Node{
	char data;
	Node *lchild=NULL, *rchild=NULL;
};

typedef struct Node node;

node* build(const string &str){
	node* root=NULL;
	unsigned long max_length=str.length();
	int k=-1;
	int top=-1;
	node *p;
	node *temp;
	node* Stack[max_length];
	for(int i=0; i<max_length; i++){
		if(str[i]=='('){
			k=0;
			top++;
			Stack[top]=p;
		}
		else if(str[i]==','){
			k=1;
		}
		else if(str[i]==')'){
			top--;
		}
		else if(isalpha(str[i])){
			temp = new node;
			temp->data = str[i];
			if(k==-1){
				root=temp;
				top++;
				Stack[top]=temp;
			}
			else if(k==0){
				if(Stack[top]==p)
					top--;
				Stack[top]->child=temp;
				top++;
				Stack[top]=temp;
			}
			else if(k==1){
				top--;
				Stack[top]->rchild=temp;
				top++;
				Stack[top]=temp;
			}
		}
	}
	return root;
}

void print_list(node* cur_node){
	cout<<cur_node->data;
	if(cur_node->lchild!=NULL){
		cout<<'(';
		print_list(cur_node->lchild);
		if(cur_node->rchild==NULL)
			cout<<",)";
	}
	if(cur_node->rchild!=NULL){
		if(cur_node->lchild==NULL)
			cout<<'(';
		cout<<',';
		print_list(cur_node->rchild);
		cout<<')';
	}
}



void delete_tree(node *&cur){
	if(cur!=NULL){
		delete_tree(cur->lchild);
		delete_tree(cur->rchild);
		delete cur;
		cur=NULL;
	}
}

void delete_all(node *&cur, char value){
	if(cur->lchild!=NULL){
		delete_all(cur->lchild, value);
	}
	if(cur->rchild!=NULL){
		delete_all(cur->rchild, value);
	}
	if(cur->data==value){
		delete_tree(cur);
	}
}


void layorder(Node* root, int max_len){
	Node *Queue[max_len];
	Node *temp;
	int head=0, tail=-1;
	tail++;
	Queue[tail]=root;
	while(head<=tail){
		temp=Queue[head];
		if(temp!=root) cout<<' ';
		cout<<temp->data;
		if(temp->lchild){
			tail++;
			Queue[tail]=temp->lchild;
		}
		if(temp->rchild){
			tail++;
			Queue[tail]=temp->rchild;
		}
		head++;
	}
}



Node* find_parent(Node *&cur, Node *&goal){
	if(cur->lchild!=NULL){
		if(cur->lchild->data==goal->data)
			return cur;
		if(find_parent(cur->lchild, goal)!=NULL)
			return find_parent(cur->lchild, goal);
	}
	if(cur->rchild!=NULL){
		if(cur->rchild->data==goal->data)
			return cur;
		if(find_parent(cur->rchild, goal)!=NULL)
			return find_parent(cur->rchild, goal);
	}
	return NULL;
}


template <typename Type> class Node{
public:
	Type data;
	Node *lchild, *rchild, *parent;
	Node(Type _data, Node<Type> *_parent=NULL){
		data = _data;
		lchild=NULL;
		rchild=NULL;
		parent=_parent;
	}	

	~Node(){
		if(lchild!=NULL){
			delete lchild;
		}
		if(rchild!=NULL){
			delete rchild;
		}
	}

	void insert(Type value){
		if(data==value){
			return;
		}
		else if(value>data){
			if(rchild==NULL){
				rchild=new Node<Type>(value, this);
			}
			else{
				rchild->insert(value);
			}
		}
		else{
			if(lchild==NULL){
				lchild=new Node<Type>(value, this);
			}
			else{
				lchild->insert(value);
			}
		}
	}

	Node<Type>* predecessor(){
		Node<Type> *temp=lchild;
		while(temp!=NULL temp->rchild!=NULL){
			temp=temp->rchild;
		}
		return temp;
	}

	Node<Type>* successor(){
		Node<Type> *temp=rchild;
		if(temp!=NULL && temp->lchild!=NULL)
			temp=temp->lchild;
		return temp;
	}

	void remove_node(Node<Type> *delete_ndoe){
		Node<Type> *temp=NULL;
		if(delete_node->lchild!=NULL){
			temp=delete_node->lchild;
			temp->father = delete_node->father;
		}
		if(delete_node->rchild!=NULL){
			temp=delete_node->rchild;
			temp->father=delete_node->father;
		}
		if(delete_node->father!=NULL){
			if(delete_node->father->lchild==delete_node){
				delete_node->father->lchild=temp;
			}
			else{
				delete_node->father->rchild=temp;
			}
			delete_node->lchild=NULL;
			delete_node->rchild=NULL;
			delete delete_node;
		}
	}

	void remove_node(Node<Type> *delete_node){
		Node<Type> *temp=NULL;
		if(delete_node->lchild!=NULL){
			temp=delete_node->lchild;
			temp->father=delete_node->father;
		}
		if(delete_node->rchild!=NULL){
			temp=delete_node->rchild;
			temp->father=delete_node->father;
		}
		if(delete_node->father!=NULL){
			if(delete_node->father->lchild==delete_node){
				delete_node->father->lchild=temp;
			}
			else{
				delete_node->father->rchild=temp;
			}
		}
		delete_node->lchild=NULL;
		delete_node->rchild=NULL;
		delete delete_node;
	}
};

bool delete_node(Type value){
	Node<Type> *delete_node, *current_node;
	current_node = search(value);
	if(current_node==NULL)
		return false;
	if(current_node->lchild!=NULL){
		delete_node=current_node->predecessor();
	}
	else if(current_node->rchild!=NULL)
		delete_node=current_node->successor();
	else{
		delete_node=current_node;
	}
	current_node->data=delete_node->data;
	remove_node(delete_node);
	return true;
}

void remove_node(Node<Type> *delete_node){
	Node<Type> *temp=NULL;
	if(delete_node->lchild!=NULL){
		temp=delete_node->lchild;
		temp->father=delete_node->father;
	}
	if(delete_node->rchild!=NULL){
		temp=delete_node->rchild;
		temp->father=delete_ndoe->father;
	}
	if(delete_node->father!=NULL){
		if(delete_node->father->lchild==delete_node){
			delete_node->father->lchild=temp;
		}
		else
			delete_node->father->rchild=temp;
	}
	delete_node->lchild=NULL;
	delete_node->rchild=NULL;
	delete delete_node;
}

Node* search(Type value){
	if(data==value)
		return this;
	else if(value>data){
		if(rchild==NULL)
			return NULL;
		else
			rchild->search(value);
	}
	else{
		if(lchild==NULL)
			return NULL;
		else
			lchild->search(value);
	}
}

bool delete_node(Type value){
		Node<Type> *delete_node, *current_node;
		current_node=search(value);
		if(current_node==NULL)
			return false;
		if(current_node->lchild!=NULL)
			delete_node=current_node->predecessor();
		else if(current_node->rchild!=NULL)
			delete_node=current_node->successor();
		else
			delete_node=current_node;
		current_node->data=delete_node->data;
		remove_node(delete_node);
		return true;
}


template <typename Type> class BinaryTree{
private:
	Node<Type> *root;
public:
	BinaryTree(){
		root=NULL;
	}	
	~BinaryTree(){
		delete root;
	}
	void insert(Type value){
		if(root==NULL)
			root = new Node<Type>(value);
		else 
			root->insert(value);
	}
	bool find(Type value){
		if(root==NULL)
			return false;
		else
			if(root->search(value)==NULL)
				return false;
			else
				return true;
	}

};



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
        if(GetHeight(treeNode->Left->Left)>GetHeight(treeNode->Left->Right))
            LL_rotate(treeNode);
        else
            LR_rotate(treeNode);
    }
    if(GetHeight(treeNode->Right)-GetHeight(treeNode->Left)>1){
        if(GetHeight(treeNode->Right->Right)>GetHeight(treeNode->Right->Left))
            RR_rotate(treeNode);
        else
            RL_rotate(treeNode);
    }
    treeNode->height = max(GetHeight(treeNode->Left), GetHeight(treeNode->Right))+1;
}


AVLTreeNode* MergeWithRoot(AVLTreeNode* R1, AVLTreeNode* R2, AVLTreeNode *&T){
    //abs needs <cstdlib>
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

















