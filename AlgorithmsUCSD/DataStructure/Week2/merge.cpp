#include <iostream>
#include <algorithm>
using namespace std;

int MAX = 0;
const int INF = 1000000;
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