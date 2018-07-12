#include <iostream>
#include <vector>
using namespace std;

const int MAX=1000000;
int heap[MAX], n;
int c = 0;

typedef pair<int, int> p;
vector<p> V;

void siftdown(int pos){
    int min_node = pos;
    if(pos*2+1 < n && heap[pos*2+1]<heap[min_node])
        min_node = pos*2 + 1;
    if(pos*2+2 < n && heap[pos*2+2]<heap[min_node])
        min_node = pos*2 + 2;
    if(min_node != pos){
        V.push_back(p{pos, min_node});
        c++;
        swap(heap[min_node], heap[pos]);
        siftdown(min_node);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>heap[i];
    }
    
    for(int i=(n-1-1)/2; i>=0; i--){
        siftdown(i);
    }
    cout<<c<<endl;
    for(int i=0; i<V.size(); i++){
        cout<<V[i].first<<' '<<V[i].second<<endl;
    }
    
}