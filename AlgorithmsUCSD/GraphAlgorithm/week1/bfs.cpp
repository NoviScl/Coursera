#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

vector<int> G[2000];
bool visited[2000];

int BFS(int u, int target){
    queue<int> bfs;
    bfs.push(u);
    while(!bfs.empty()){
        int t = bfs.front();
        if(t==target)
            return 1;
        bfs.pop();
        for(int i: G[t]){
            if(!visited[i]){
                visited[i] = 1;
                bfs.push(i);
            }
        }
    }
    return 0;
}

int main(){
    int n, m, u, v;
    cin>>n>>m;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<m; i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    cin>>u>>v;
    cout<<BFS(u, v);
}