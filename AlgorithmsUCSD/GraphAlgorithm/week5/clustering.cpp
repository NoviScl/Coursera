#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int x[300], y[300], visited[300], father[300];
struct edge{
	int from, to;
	double dist;
	edge(int a, int b, double c){
		from = a;
		to = b;
		dist = c;
	}
};

vector<edge> E;

double dist(int ia, int ib){
	return sqrt(pow(x[ia]-x[ib], 2)+pow(y[ia]-y[ib], 2));
}

bool cmp(edge a, edge b){
	return a.dist < b.dist;
}

int find_father(int v){
	if(father[v]==v)
		return v;
	father[v] = find_father(father[v]);
	return father[v];
}

bool merge(int va, int vb){
	int fa = find_father(va);
	int fb = find_father(vb);
	if(fa==fb) return false;
	father[fa] = fb;
	return true;
}

double kruskal(int N, int Nf){
	int fathers=N;
	for(edge e: E){
		if(fathers==Nf && merge(e.from, e.to)){
			return e.dist;
		}
		if(merge(e.from, e.to)){
			fathers--; //lost one father
		}
	}
	return -1; 
}

int main(){
	int n, Nfather;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i];
		father[i] = i;
		visited[i] = 0;
	}
	cin>>Nfather;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			E.push_back(edge(i, j, dist(i,j)));
		}
	}
	sort(E.begin(), E.end(), cmp);
	cout<<setprecision(10)<<kruskal(n, Nfather)<<endl;
}


