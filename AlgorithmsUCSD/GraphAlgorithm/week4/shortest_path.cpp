#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
const ll INF = 9999999999999;
const int maxN = 1100;
const int maxM = 11000;
int u[maxM], v[maxM], d[maxM];
vector<int> G[maxN];
ll dist[maxN];
queue<int> neg;
int N, M;

void bellman_ford(int S){
    bool changed = false;
    dist[S]=0;
    for(int i=1; i<=N-1; i++){
        changed = false;
        //must check u[e] not INF otherwise -ve edge will update for unreachable nodes
        for(int e=1; e<=M; e++){
            if(dist[u[e]]<INF && dist[v[e]]>dist[u[e]]+d[e]){
                dist[v[e]]=dist[u[e]]+d[e];
                changed=true;
            }
        }
        if(!changed) break;
    }
    if(!changed) return;
    for(int e=1; e<=M; e++){
        if(dist[u[e]]<INF && dist[v[e]]>dist[u[e]]+d[e]){
            neg.push(u[e]);
            neg.push(v[e]);
        }
    }
}

void BFS(){
    int visited[maxN];
    memset(visited, 0, sizeof(visited));
    while(!neg.empty()){
        int v = neg.front();
        neg.pop();
        if(visited[v]) continue;
        visited[v]=1;
        dist[v]=-INF;
        for(int adj: G[v]){
            neg.push(adj);
        }
    }
}


int main(){
    int s;
    cin>>N>>M;
    for(int i=1; i<=N; i++)
        dist[i]=INF;
    for(int i=1; i<=M; i++){
        cin>>u[i]>>v[i]>>d[i];
        G[u[i]].push_back(v[i]);
    }
    cin>>s;
    bellman_ford(s);
    BFS();
    for(int i=1; i<=N; i++){
        if(dist[i]==INF)
            cout<<'*'<<endl;
        else if(dist[i]==-INF)
            cout<<'-'<<endl;
        else
            cout<<dist[i]<<endl;
    }
}




//6 7
//1 2 10
//2 3 5
//1 3 100
//3 5 7
//5 4 10
//4 3 -18
//6 1 -1
//1






