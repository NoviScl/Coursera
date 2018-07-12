#include <iostream>
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

bool inOrder(int cur){
    if(cur==-1) return true;
    if(!inOrder(tree[cur].left))
        return false;
    if(tree[cur].key < Prev)
        return false;
    Prev = tree[cur].key;
    if(!inOrder(tree[cur].right))
        return false;
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
    
    if(inOrder(0))
        cout<<"CORRECT"<<endl;
    else
        cout<<"INCORRECT"<<endl;
    
}
