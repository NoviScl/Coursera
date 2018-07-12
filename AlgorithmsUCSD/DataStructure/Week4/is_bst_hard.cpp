#include <iostream>
#include <vector>
using namespace std;

const int N = 200000;
typedef long long ll;

struct node{
    ll key;
    int left=-1, right=-1;
};

const ll MAX = 9999999999;
node tree[N];
ll Prev = -MAX;
int side = 0;
vector<int> Nodes;

void inOrder(int cur){
    if(cur==-1) return;
    inOrder(tree[cur].left);
    Nodes.push_back(cur);
    inOrder(tree[cur].right);
}

bool check(){
    inOrder(0);
    for(int i=0; i<Nodes.size()-1; i++){
        if(tree[Nodes[i]].key>tree[Nodes[i+1]].key) return false;
        if(tree[Nodes[i]].key==tree[Nodes[i+1]].key && Nodes[i] == tree[Nodes[i+1]].left) return false;
    }
    return true;
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
    
    if(check())
        cout<<"CORRECT"<<endl;
    else
        cout<<"INCORRECT"<<endl;
    
}
