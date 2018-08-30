#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm> //fill
using namespace std;

const int MAX = 150000;
int dist[MAX];
vector<vector<int> > Graph(MAX);
queue<int> Q;

void BFS(int S, int E){
    dist[S] = 0;
    Q.push(S);
    while(!Q.empty()){
        int T = Q.front();
        Q.pop();
        for(int V: Graph[T]){
            if(dist[V]==-1){
                Q.push(V);
                dist[V] = dist[T]+1;
                if(V==E)
                    return;
            }
        }
    }
}

int main(){
    int n, m, u, v;
    cin>>n>>m;
    fill(dist, dist+MAX, -1);
    for(int i=1; i<=m; i++){
        cin>>u>>v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    cin>>u>>v;
    BFS(u, v);
    cout<<dist[v]<<endl;
    
}


//4 4
//1 2
//4 1
//2 3
//3 1
//2 4








