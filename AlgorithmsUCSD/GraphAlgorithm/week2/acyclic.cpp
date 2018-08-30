#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int state[2000];
//state: 0: not visited, 1: visiting, 2: visited
bool cycle = false;
stack<int> topoSort;
vector<int> G[2000];


void dfs(int node){
    if(state[node]==2) return;
    if(state[node]==1){
        cycle = true;
        return;
    }
    //already found cycle, cannot topo sort
    if(cycle) return;
    state[node]=1;
    for(int adj: G[node]){
        dfs(adj);
        if(cycle) return;
    }
    state[node] = 2;
    topoSort.push(node); //put sink into stack
}

int main(){
    int n, m, u, v;
    memset(state, 0, sizeof(state));
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        G[u].push_back(v);
    }
    
    for(int i=1; i<=n; i++){
        if(state[i]==0){
            dfs(i);
            if(cycle) break;
        }
    }
    cout<<(cycle)<<endl;
}
