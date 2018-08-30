#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1500;
const int INF = 999999999;
int dis[MAX];
struct edge{
    int end, dist;
    edge(int a, int b){
        end = a;
        dist = b;
    }
};
vector<edge> G[MAX];
int N, M;

struct cmp{
    bool operator()(edge a, edge b){
        return a.dist > b.dist;
    }
};


int dijkstra(int S, int E){
    priority_queue<edge, vector<edge>, cmp> Q;
    dis[S]=0;
    Q.push(edge(S, dis[S]));
    while(!Q.empty()){
        edge t = Q.top();
        Q.pop();
        if(t.end==E) return t.dist;
        for(edge e: G[t.end]){
            if(dis[e.end]>t.dist+e.dist){
                dis[e.end]=t.dist+e.dist;
                Q.push(edge(e.end, dis[e.end]));
            }
        }
    }
    return -1;
}


int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++)
        dis[i]=INF;
    int u, v, d;
    for(int i=1; i<=M; i++){
        cin>>u>>v>>d;
        G[u].push_back(edge(v, d));
    }
    cin>>u>>v;
    cout<<dijkstra(u, v)<<endl;
}



//4 4
//1 2 1
//4 1 2
//2 3 2
//1 3 5
//1 3

//3 3
//1 2 7
//1 3 5
//2 3 2
//3 2








