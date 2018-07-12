#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int cur_color = 0;
int color[2000];
vector<int> G[2000];

void dfs(int cur){
    color[cur] = cur_color;
    for(int i: G[cur]){
        if(color[i]==0){
            dfs(i);
        }
    }
}

int main(){
    int n, m, u, v;
    memset(color, 0, sizeof(color));
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++){
        if(color[i]==0){
            cur_color++;
            dfs(i);
        }
    }
    cout<<cur_color<<endl;
}


