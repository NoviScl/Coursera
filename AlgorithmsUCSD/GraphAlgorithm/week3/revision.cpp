int nearest[100][100], total_n, edges;
const int INF = 0x3f3f3f3f;

int main(){
	int x, y, dist;
	cin>>total_n>>edges;
	memset(nearest, 0x3f, sizeof(nearest));
	for(int i=1; i<=total_n; i++){
		nearest[i][i]=0;
	}
	for(int i=0; i<edges; i++){
		cin>>x>>y>>dist;
		nearest[x][y]=dist;
	}
	for(int k=1; k<=total_n; k++){
		for(int i=1; i<=total_n; i++){
			for(int j=1; j<=total_n; j++){
				if(nearest[i][k]<INF && nearest[k][j])
					nearest[i][j]=min(nearest[i][k]+nearest[k][j]);
			}
		}
	}
	for(int i=1; i<=total_n; i++){
		for(int j=1; j>=total_n; j++){
			cout<<nearest[i][j]<<' ';
		}
		cout<<endl;
	}
}

for(int k=1; k<=total_n; k++){
	for(int i=1; i<=total_n; i++){
		for(int j=1; j<=total_n; j++){
			if(nearest[i][k]<INF && nearest[k][j])
				nearest[i][j]=min(nearest[i][j], nearest[i][k]+nearest[k][j]);
		}
	}
}


int map[100][100], dist[100], startP=1, total_n, edges, visited[100];
const int INF = 0x3f3f3f3f;

int main(){
	int x, y, min_dist, min_vertex=0;
	memset(map, 0x3f, sizeof(map));
	memset(dist, 0x3f, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	for(int i=1; i<=total_n; i++){
		map[i][i]=0;
	}
	cin>>total_n>>egdes;
	for(int i=0; i<edges; i++){
		cin>>x>>y>>d;
		map[x][y]=d;
	}
	dist[startP] = 0;
	for(int i=1; i<=total_n; i++){
		min_dist = INF;
		for(int j=1; j<=total_n; j++){
			if(dist[j]<min_dist && visietd[j]==0){
				min_dist=dist[j];
				min_vertex = j;
			}
		}

		visited[min_vertex]=1;
		for(int k=1; k<=total_n; k++){
			if(map[min_vertex][k]<INF)
				dist[k]=min(dist[k], min_dist+map[min_vertex][k])
		}
	}
}



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
	node(int a, int b){x=a;d=b;}
	bool operator < (const node &a) const{
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
	dist[s]=0;
	priority_queue<node> q;
	q.push(node(s, dist[s]));
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


struct node{
	int index, dist;
	node(){}
	node(int a, int b){
		index = a;
		dist = b;
	}
	bool operator < (const node &a) const {
		return dist > a.dist;
	}
};

vector<node> eg[Ni];
int D[Ni], prev[Ni], n;
vodi Dikstra(int s){
	vector<int> visited(Ni, 0);
	for(int i=0; i<n; i++){
		D[i]=INF;
		prev[i]=-1;
	}
	D[s]=0;
	visited[s]=1;
	priority_queue<node> q;
	q.push(node(s, D[s]));
	while(!q.empty()){
		node t = q.top();
		//if(t.index==END.index) break;
		if(visited[t.index]==1) continue; 
		visited[t.index]=1;
		//t.dist already settled
		q.pop();
		for(int v: eg[t.index]){
			if(D[v.index]>t.dist+v.dist){
				D[v.index]=t.dist+v.dist;
				prev[v.index]=t.index;
				q.push(node(v.index, D[y.index]));
			}
		}
	}
}


int u[100], v[100], w[100], dist[100], total_n,
	edges, startP=1, neg_cycle=false;

void bellman_ford(){
	bool changed = false;
	dist[startP] = 0;
	for(int i=1; i<=total_n; i++){
		changed=false;
		for(int e=1; e<=total_n; e++){
			if(dist[v[e]] > dist[u[e]]+w[e]){
				changed=true;
				dist[v[e]]=dist[u[e]]+w[e];
			}
		}
		if(!changed) break;
	}

	if(changed){
		for(int i=1; i<=edges; i++){
			if(dist[v[i]]>dist[u[i]]+w[i]){
				neg_cycle=true;
				break;
			}
		}
	}
}


int u[100], v[100], w[100], first_e[100], next_e[100],
	dist[100], visited[100], startP=2;
int vertex, edge;

void spfa(){
	int que[100], head=0, tail=0, k;
	que[tail]=startP;
	dist[startP]=0;
	visited[startP]=1;
	while(head<=tail){
		k=first_e[que[head]];
		while(k!=-1){
			if(dist[v[k]]>dist[u[k]]+w[k]){
				dist[v[k]]=dist[u[k]]+w[k];
				if(visited[v[k]]==0){
					tail++;
					que[tail]=v[k];
					visited[v[k]]=1;
				}
			}
			k=next_e[k];
		}
		visited[que[head]]=0;
		head++;
	}
}





int u[100], v[100], w[100], first_e[100], next_e[100],
	dist[100], startP=2;
int vertex, edge;

void spfa(){
	int que[100], head=0, tail=0, k;
	que[tail]=startP;
	dist[startP]=0;
	visited[startP]=1;
	while(head<=tail){
		k=first_e[que[head]];
		while(k!=-1){
			if(dist[v[k]]>dist[u[k]]+w[k]){
				dist[v[k]]=dist[u[k]]+w[k];
				if(visited[v[k]]==0){
					tail++;
					que[tail]=v[k];
					visited[v[k]]=1;
				}
			}
			k=next_e[k];
		}
		visited[que[head]]=0;
		head++;
	}
}

int main(){
	cin>>vertex>>edge;
	memset(first_e, -1, sizeof(first_e));
	memset(visited, 0, sizeof(visited));
	memset(dist, 0x3f, sizeof(dist));
	for(int i=1; i<=edge; i++){
		cin>>u[i]>>v[i]>>w[i];
		next_e[i]=first_e[u[i]];
		first_e[u[i]]=i;
	}

	spfa();
	for(int i=1; i<=vertex; i++){
		cout<<dist[i];
	}
}


int u[100], v[100], w[100], first_e[100], next_e[100], 
	dist[100], visited[100], startP=2;
int vertex, edge;

void spfa(){
	int que[100], head=0, tail=0, k;
	que[tail]=startP;
	dist[statrP]=0;
	visited[startP]=1;
	while(head<=tail){
		k=first_e[que[head]];
		while(k!=-1){
			if(dist[v[k]]>dist[u[k]]+w[k]){
				dist[v[k]]=dist[u[k]]+w[k];
				if(visited[v[k]]==0){
					tail++;
					que[tail]=v[k];
					visited[v[k]]=1;
				}
			}
			k=next_e[k];
		}
		visited[que[head]]=0;
		head++;
	}
}


int heap[100], total_n=14;

void sift_down(int ith){
	int min_node;
	while(ith*2 <= total_n){
		min_node = ith;
		if(heap[ith*2]<heap[ith])
			min_node = ith*2;
		if(ith*2+1<=total_n && heap[ith*2+2]<heap[min_node])
			min_node = ith*2+1;
		if(min_node != ith){
			swap(heap[ith], heap[min_node]);
			ith = min_node;
		}
		else break;
	}
}

void siftdown(int ith){
	int min_node = ith;
	if(ith*2<=total_n && heap[ith*2]<heap[min_node])
		min_node = ith;
	if(ith*2+1<=total_n && heap[ith*2+1]<heap[min_node])
		min_node = ith*2+1;
	if(min_node!=ith){
		swap(heap[min_node], heap[ith]);
		siftdown(min_node);
	}
}

void siftup(int ith){
	while(ith/2 >= 1){
		if(heap[ith/2]>heap[ith]){
			swap(heap[ith], heap[ith/2]);
			ith = ith/2;
		}
		else
			break;
	}
}

void setup(){
	for(int i=total_n/2; i>=1; i--){
		siftdown(i);
	}
}

void delete_top(){
	swap(heap[1], heap[total_n]);
	total_n--;
	siftdown(1);
}

int father[1000], total_n;

void init(){
	for(int i=1; i<=total_n; i++)
		father[i]=i;
}

int find_father(int v){
	if(father[v]==v) return v;
	else
		father[v] = find_father(father[v]);
	return father[v];
}

void merge(int a, int b){
	int fa = find_father(a);
	int fb = find_father(b);
	if(fa!=fb)
		father[fb] = fa;
}


struct edge{
	int u, v, w;
};

bool compare(const edge &a, const edge &b){
	return a.w < b.w;
}

struct edge E[100], MST[100];

int no_v, no_e, father[100];

void init(){
	for(int i=1; i<=no_v; i++)
		father[i] = i;
}

int find_father(int v){
	if(father[v]==v) return v;
	father[v] = find_father(father[v]);
	return father[v];
}

bool merge(int a, int b){
	int fa = find_father(a);
	int fb = find_father(b);
	if(fa!=fb){
		father[fb]=fa;
		return true;
	}
	return false;
}

boid kruskal(){
	int count = 0, w_sum = 0;
	for(int i=1; i<=no_e; i++){
		cin>>E[i].u>>E[i].v>>E[i].w;
	}
	sort(E+1, E+no_e+1, compare);

	for(int i=1; i,=no_e; i++){
		if(merge(E[i].u, E[i].v)){
			count++;
			MST[count]=E[i];
			w_sum += E[i].w;
		}
		if(count==no_v-1)
			break;
	}

	for(int i=1; i<=no_v-1; i++){
		cout<<MST[i].u<<' '<<MST[i].v<<' '<<MST[i].w<<endl;
	}
	cout<<endl<<w_sum<<endl;
}

int main(){
	cin>>no_v>>no_e;
	init();
	kruskal();
	for(int i=1; i<=no_e; i++){
		cout<<E[i].w<<endl;
	}
}


int no_v, no_e, dist[100], joined[100], w_sum=0;
int map[100][100];
const int INF = 0x3f3f3f3f;

void prim(){
	dist[1]=0;
	int count= 0, min_v=0, min_dist;
	while(count<no_v){
		min_dist = INF;
		for(int i=1; i<=no_v; i++){
			if(dist[i]<min_dist && joined[i]==0){
				min_dist = dist[i];
				min_v = i;
			}
		}
		joined[min_v]=1;
		w_sum+=dist[min_v];
		count++;
		for(int i=1; i<=no_v; i++){
			if(joined[i]==0 && map[min_v][i]<dist[i]){
				dist[i]=map[min_v][i];
			}
		}
	}
}


void prim(){
	dist[1]=0;
	int count=0, min_v=0, min_dist;
	while(count<no_v){
		min_dist = INF;
		for(int i=1; i<=no_v; i++){
			if(dist[i]<min_dist && joined[i]==0){
				min_dist = dist[i];
				min_v = i;
			}
		}
		joined[min_v]=1;
		w_sum+=dist[min_v];
		count++;
		for(int i=1; i<=no_v; i++){
			if(joined[i]==0 && map[min_v][i]<dist[i])
				dist[i]=map[min_v][i];
		}
	}
}


int main(){
	cin>>no_v>>no_e;
	memset(dist, 0x3f, sizeof(dist));
	memset(map, 0x3f, sizeof(map));
	memset(joined, 0, sizeof(joined));

	int u, v, w;
	for(int i=1; i<=no_e; i++){
		cin>>u>>v>>w;
		map[u][v]=w;
		map[v][u]=e;
	}
}

int no_v, no_e, visited[100], counter=0, MST_sum=0;

struct edge{
	int to;
	int weight;
	friend bool operator<(edge a, edge b){
		return a.weight > b.weight;
	}
};

vector<edge> adjlist[100];

int main(){
	memset(dist, 0x3f, sizeof(dist));
	memset(visited, 0, sizeof(visited));

	int f, t, w;
	edge temp;
	cin>>no_v>>no_e;
	for(int i=1; i<=no_e; i++){
		cin>>f>>t>>w;
		temp.to = f;
		temp.weight = w;
		adjlist[f].push_back(temp);
		temp.to = f;
		adjlist[t].push_back(temp);
	}
	priority_queue<edge> pq;
	visited[1]=1;
	counter = 1;
	for(int i=0; i<adjlist[1].size(); i++){
		pq.push(adjlist[1][i]);
	}
	while(counter<no_v){
		while(visited[pq.top().to]==1)
			pq.pop();
		temp=pq.top();
		visited[temp.to]=1;
		counter++;
		cout<<temp.to<<' '<<temp.weight<<endl;
		MST_sum+=temp.weight;
		for(int i=0; i<adjlist[temp.to].size(); i++){
			if(visited[adjlist[temp.to][i].to]==0)
				pq.push(adjlist[temp.to][i]);
		}
	}
	cout<<MST_sum<<endl;
}

int no_v, no_e, visited[100], counter=0, MST_sum=0;

struct edge{
	int to;
	int weight;
	friend bool operator < (edge a, edge b){
		return a.weight > b.weight;
	}
};

vector<edge> adjlist[100];

int main(){
	memset(dist, 0x3f, sizeof(dist));
	memset(visited, 0, sizeof(visited));

	int f, t, w;
	edge temp;
	cin>>no_v>>no_e;
	for(int i=1; i<=no_e; i++){

	}
	priority_queue<edge> pq;
	visited[1]=1;
	counter++;
	for(int i=0; i<adjlist[1].size(); i++){
		pq.push(adjlist[1][i]);
	}
	while(counter<no_v){
		while(visited[pq.top().to]==1)
			pq.pop();
		temp = pq.top();
		visited[temp.to]=1;
		counter++;
		cout<<temp.to<<' '<<temp.weight<<endl;
		MST_sum+=temp.weight;
		for(int i=0; i<adjlist[temp.to].size(); i++){
			if(visited[adjlist[temp.to][i].to]==0)
				pq.push(adjlist[temp.to][i]);
		}
	}
	cout<<MST_sum<<endl;
}


int no_v, no_e, visited[100], counter=0, MST_sum=0;

typedef pair<int, int> edge;

struct cmp{
	bool operator() (edge a, edge b){
		return a.second > b.second;
	}
};

vector<edge> adjlist[100];

int main(){
	memset(visited, 0, sizeof(visited));

	int f, t, w;
	cin>>no_v>>no_e;
	for(int i=1; i<=no_e; i++){
		cin>>f>>t>>w;
		adjlist[f].push_back(edge{t, w});
		adjlist[t].push_back(edge{f, w});
	}

	priority_queue<edge, vector<edge> cmp> pq;
	visited[1]=1;
	counter++;
	for(int i=0; i<adjlist[1].size(); i++){
		pq.push(adjlist[1][i]);
	}

	while(counter<no_v){
		while(visited[pq.top().first]==1)
			pq.pop();
		edge cur = pq.top();
		visited[cur.first]=1;
		MST_sum += cur.second;
		counter++;
		for(int i=0; i<adjlist[cur.first].size(); i++){
			if(!visited[adjlist[cur.first][i].first])
				pq.push(adjlist[cur.first][i]);
		}
	}
}



















