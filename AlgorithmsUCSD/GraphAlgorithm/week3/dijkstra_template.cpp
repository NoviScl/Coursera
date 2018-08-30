#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int Ni = 10000;
const int INF = 1<<27;

struct node{
	int x, d;
	node(){}
	node(int a, int b){x=a;y=b;}
	bool operator < (const node & a) const{
		if(d==a.d) return x<a.x;
		else return d > a.d;
	}
};

vector<node> eg[Ni];
int dis[Ni], prev[Ni], n;
void Dijkstra(int s){
	int i;
	for(int i=0; i<n; i++){
		dis[i]=INF;
		prev[i]=-1;
	}
	dis[s] = 0;
	priority_queue<node> q;
	q.push(node(s, dis[s]));
	while(!q.empty()){
		node t = q.top();
		q.pop();
		for(i=0; i<eg[t.x].size(); i++){
			node y = eg[t.x][i];
			if(dis[y.x]>t.d+y.d){
				dis[y.x]=t.d+y.d;
				prev[y.x]=t.x;
				q.push(node(y.x, dis[y.x]));
			}
		}
	}
}

int main(){
	int a, b, d, m;
	while(scanf("%d%d", &n, &m), n+m){
		for(int i=0; i<=n; i++) eg[i].clear();
			while(m--){
				scanf("%d%d%d", &a, &b, &d);
				eg[a].push_back(node(b, d));
				eg[b].push_back(node(a, d));
			}
			Dijkstra(1);
			printf("%d\n", dis[n]);
	}
	return 0;
}
























