#include <iostream>
using namespace std;

const int N = 200000;
typedef long long ll;

struct node{
	ll key;
	int left=-1, right=-1;
};

node tree[N];

void preOrder(int i){
	if(i==-1) return;
	cout<<tree[i].key<<' ';
	preOrder(tree[i].left);
	preOrder(tree[i].right);
}

void inOrder(int i){
	if(i==-1) return;
	inOrder(tree[i].left);
	cout<<tree[i].key<<' ';
	inOrder(tree[i].right);
}

void postOrder(int i){
	if(i==-1) return;
	postOrder(tree[i].left);
	postOrder(tree[i].right);
	cout<<tree[i].key<<' ';
}

int main(){
	int n, k, l, r;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>k>>l>>r;
		tree[i].key = k;
		tree[i].left = l;
		tree[i].right = r;
	}
	
	inOrder(0);
	cout<<endl;
	preOrder(0);
	cout<<endl;
	postOrder(0);
	cout<<endl;

}
