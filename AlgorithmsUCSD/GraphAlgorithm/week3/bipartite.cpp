#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 150000;
vector<vector<int> > G(MAX);
int color[MAX];


//note: only one node with no edges is also a bipartite graph
//because the definition is every edge has 2 different colors
bool BFS(int S){
    queue<int> Q;
    Q.push(S);
    color[S]=0;
    while(!Q.empty()){
        int T = Q.front();
        Q.pop();
        for(int V: G[T]){
            if(color[V]==color[T])
                return false;
            else if(color[V]==-1){
                color[V] = 1-color[T];
                Q.push(V);
            }
        }
    }
    return true;
}


int main(){
    int n, m, u, v;
    fill(color, color+MAX, -1);
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(color[i]==-1 && BFS(i)==false){
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<1<<endl;
    
}
