#include <iostream>
using namespace std;

const int MAX = 11000;
const int INF = 999999999;
int u[MAX], v[MAX], d[MAX], N, M, dist[1100];

bool bellman_ford(){
    bool changed=false;
    for(int i=1; i<=N-1; i++){
        changed=false;
        for(int e=1; e<=M; e++){
            if(dist[v[e]]>dist[u[e]]+d[e]){
                dist[v[e]]=dist[u[e]]+d[e];
                changed=true;
            }
        }
        if(!changed) break;
    }
    if(!changed) return false;
    changed=false;
    for(int e=1; e<=M; e++){
        if(dist[v[e]]>dist[u[e]]+d[e]){
            dist[v[e]]=dist[u[e]]+d[e];
            changed=true;
        }
    }
    return changed;
}

int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++)
        dist[i]=INF;
    for(int i=1; i<=M; i++){
        cin>>u[i]>>v[i]>>d[i];
    }
    cout<<bellman_ford()<<endl;
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








