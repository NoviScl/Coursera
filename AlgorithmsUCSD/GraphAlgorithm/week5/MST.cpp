#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

struct pt{
    int x, y;
};

struct edge{
    int from, to;
    double dist;
    edge(int a, int b, double c){
        from = a;
        to = b;
        dist = c;
    }
};

bool cmp(edge a, edge b){
    return a.dist < b.dist;
}

vector<edge> E;
int father[300];

double dist(pt a, pt b){
    return sqrt(pow(a.x-b.x, 2.0)+pow(a.y-b.y, 2.0));
}


int find_father(int v){
    if(father[v]==v)
        return v;
    else
        father[v] = find_father(father[v]);
    return father[v];
}

bool merge(int va, int vb){
    int fa = find_father(va);
    int fb = find_father(vb);
    if(fa==fb) return false;
    else{
        father[fa] = fb;
        return true;
    }
}

double minimum_distance(int N) {
    double result = 0.;
    int counter=0;
    for(edge e: E){
        if(merge(e.from, e.to)){
            result+=e.dist;
            counter++;
        }
        if(counter==N-1) break;
    }
    return result;
}



int main() {
    size_t n;
    cin >> n;
    vector<pt> P(n);
    for (size_t i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
        father[i] = i;
    }
    for(size_t i=0; i<n; i++){
        for(size_t j=i+1; j<n; j++){
            E.push_back(edge(i, j, dist(P[i], P[j])));
        }
    }
    sort(E.begin(), E.end(), cmp);
    cout << setprecision(10) << minimum_distance(n) << endl;
}



//4
//0 0
//0 1
//1 0
//1 1





