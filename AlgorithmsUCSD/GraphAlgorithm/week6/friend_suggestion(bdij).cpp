#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
using namespace std;


// External vector of size 2 - for forward and backward search.
// Internal 2-dimensional vector is vector of adjacency lists for each node.
typedef vector<vector<vector<int>>> Adj;

typedef long long ll;

// Vector of two priority queues - for forward and backward searches.
// Each priority queue stores the closest unprocessed node in its head.
// default pq is big root heap
typedef vector<priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>> Queue;

const ll INFINITY = numeric_limits<ll>::max()/4;

class Bidijkstra{
    // number of nodes
    int n_;
    
    // Graph adj_[0] and cost_[0] correspond to the initial graph,
    // adj_[1] and cost_[1] correspond to the reversed graph.
    // Graphs are stored as vectors of adjacency lists corresponding
    // to nodes.
    // Adjacency list itself is stored in adj_, and the corresponding
    // edge costs are stored in cost_.
    Adj adj_;
    Adj cost_;
    // distance_[0] stores distances for the forward search,
    // and distance_[1] stores distances for the backward search.
    vector<vector<ll>> distance_;
    // Stores all the nodes visited either by forward or backward search.
    vector<int> workset_;
    // Stores a flag for each node which is True iff the node was visited
    // either by forward or backward search.
    vector<bool> visited_;
    
public:
    Bidijkstra(int n, Adj adj, Adj cost)
    :n_(n), adj_(adj), cost_(cost), distance_(2, vector<ll>(n, INFINITY)), visited_(n)
    {
        workset_.reserve(n);
    }
    
    // Initialize the data structures before new query,
    // clear the changes made by the previous query.
    void clear(){
        for(int i=0; i<workset_.size(); ++i){
            int v = workset_[i];
            distance_[0][v] = distance_[1][v]=INFINITY;
            visited_[v] = false;
        }
        workset_.clear();
    }
    
    // Processes visit of either forward or backward search
    // (determined by value of side), to node v trying to
    // relax the current distance by dist.
    void visit(Queue& q, int side, int v, ll dist){
        if(distance_[side][v] > dist){
            distance_[side][v] = dist;
            q[side].push({distance_[side][v], v});
            workset_.push_back(v);
        }
    }
    
    int extractMin(Queue& q, int side){
        pair<ll, int> p = q[side].top();
        q[side].pop();
        return p.second;
    }
    
    void Process(Queue& q, int side, int u, vector<vector<int>> &adj, const vector<vector<int>> &cost){
        for(int i=0; i<adj[u].size(); ++i){
            int v = adj[u][i];
            int w = cost[u][i];
            visit(q, side, v, distance_[side][u]+w);
        }
    }
    
    ll ShortestPath(int v){
        ll dist = INFINITY;
        for(int u: workset_){
            if(distance_[0][u]+distance_[1][u]<dist)
                dist = distance_[0][u]+distance_[1][u];
        }
        if(dist==INFINITY)
            return -1;
        return dist;
    }
    
    ll Query(int s, int t){
        clear();
        Queue q(2);
        visit(q, 0, s, 0);
        visit(q, 1, t, 0);
        while(!q[0].empty() && !q[1].empty()){
            int v = extractMin(q, 0);
            Process(q, 0, v, adj_[0], cost_[0]);
            if(visited_[v] == true)
                return ShortestPath(v);
            visited_[v] = true;
            
            int v_r = extractMin(q, 1);
            Process(q, 1, v_r, adj_[1], cost_[1]);
            if(visited_[v_r]==true)
                return ShortestPath(v_r);
            visited_[v_r] = true;
        }
        return -1;
    }
};

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    Adj adj(2, vector<vector<int>>(n));
    Adj cost(2, vector<vector<int>>(n));
    for(int i=0; i<m; i++){
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[0][u-1].push_back(v-1);
        cost[0][u-1].push_back(c);
        adj[1][v-1].push_back(u-1);
        cost[1][v-1].push_back(c);
    }
    
    Bidijkstra bidij(n, adj, cost);
    
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%lld\n", bidij.Query(u-1, v-1));
    }
}







