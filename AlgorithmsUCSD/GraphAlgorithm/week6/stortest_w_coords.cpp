#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <cmath>
#include <map>
using namespace std;

typedef vector<vector<int>> Adj;
typedef long long ll;
typedef priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Queue;

const ll INF = numeric_limits<ll>::max()/4;

class AStar{
    int n_;
    Adj adj_;
    Adj cost_;
    vector<ll> distance_;
    vector<bool> visited_;
    vector<int> workset_;
    vector<ll> p_;
    // Coordinates of the nodes
    vector<pair<ll, ll>> xy_;
    
public:
    AStar(int n, Adj adj, Adj cost, vector<pair<ll, ll>> xy)
    : n_(n), adj_(adj), cost_(cost), distance_(vector<ll>(n_, INF)),
    visited_(n), xy_(xy), p_(vector<ll>(n, -1))
    {
        workset_.reserve(n);
    }
    
    void clear(){
        for(int i=0; i<workset_.size(); i++){
            int v=workset_[i];
            distance_[v] = INF;
            visited_[v] = false;
            p_[v] = -1;
        }
        workset_.clear();
    }
    
    void visit(Queue& q, int v, ll dist, ll measure){
        if(distance_[v] > dist){
            distance_[v] = dist;
            q.push({distance_[v] + measure, v});
            workset_.push_back(v);
        }
    }
    
    
    ll Potential(int u, int t){
        if(p_[u]==-1){
            pair<ll, ll> p_u = xy_[u];
            pair<ll, ll> p_v = xy_[t];
            p_[u] = sqrt(pow((p_u.first-p_v.first),2)+pow((p_u.second-p_v.second),2));
        }
        return p_[u];
    }
    
    int extractMin(Queue& q) {
        pair<ll,int> p = q.top();
        q.pop();
        return p.second;
    }
    
    void Process(Queue& q, int u, int t, vector<vector<int>> &adj, const vector<vector<int>> &cost){
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(visited_[v] != true){
                int w = cost[u][i];
                // visit(q, v, distance_[u]+w, Potential(v, t)-Potential(u, t)); //this doesn't work
                visit(q, v, distance_[u]+w, Potential(v, t));            	
            }
        }
    }
    
    ll query(int s, int t){
        clear();
        Queue q;
        visit(q, s, 0, Potential(s, t));
        while(!q.empty()){
            int v = extractMin(q);
            if(v==t){
                if(distance_[t] != INF)
                    return distance_[t];
                else
                    return -1;
            }
            if(visited_[v]!=true){
                Process(q, v, t, adj_, cost_);
                visited_[v] = true;
            }
        }
        return -1;
    }
};

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pair<ll, ll>> xy(n);
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        xy[i] = make_pair(a, b);
    }
    Adj adj(n);
    Adj cost(n);
    for(int i=0; i<m; i++){
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u-1].push_back(v-1);
        cost[u-1].push_back(c);
    }
    
    AStar astar(n, adj, cost, xy);
    
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%lld\n", astar.query(u-1, v-1));
    }
}


















