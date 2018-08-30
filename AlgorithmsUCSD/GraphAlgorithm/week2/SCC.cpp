#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

//we need to use the reverse graph to find the sink
//cannot use DFS on original graph because the smallest post order may not be a sink
//the only guarantee is that the largest post order is a source
//one counter-eg: 1->2->3->2->4
//3 has smallest post but is not in a sink component

//use two dfs, one for ordering, one for labelling SCCs

int cur=0, SCC[15000];
bool visited[15000];
vector<vector<int> > G(15000);
vector<vector<int> > reverseG(15000);
stack<int> postOrder;

void dfsForOrder(int node){
    if(visited[node]) return;
    visited[node] = 1;
    for(int v: reverseG[node])
        dfsForOrder(v);
    postOrder.push(node);
}

void dfs(int node){
    if(SCC[node]>0) return;
    SCC[node] = cur;
    for(int v: G[node])
        dfs(v);
}


int main(){
    int n, m, u, v;
    memset(visited, 0, sizeof(visited));
    memset(SCC, 0, sizeof(SCC));
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        G[u].push_back(v);
        reverseG[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++){
        if(!visited[i])
            dfsForOrder(i);
    }
    
    while(!postOrder.empty()){
        int v = postOrder.top(); //sink
        if(SCC[v]==0){
            cur++;
            dfs(v);
        }
        postOrder.pop();
    }
    cout<<cur<<endl;
}




