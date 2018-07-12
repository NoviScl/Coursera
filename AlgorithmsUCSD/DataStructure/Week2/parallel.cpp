#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
struct thread{
    ll start_time=0, index;
};

struct cmp{
    bool operator()(thread a, thread b){
        if(a.start_time == b.start_time){
            return a.index > b.index;
        }
        return a.start_time > b.start_time;
    }
};

int main(){
    ll threads, tasks;
    cin>>threads>>tasks;
    ll t;
    priority_queue<thread, vector<thread>, cmp> pq;
    
    for(ll i=0; i<threads; i++){
        thread temp;
        temp.start_time = 0;
        temp.index = i;
        pq.push(temp);
    }
    
    for(ll i=0; i<tasks; i++){
        cin>>t;
        cout<<pq.top().index<<' '<<pq.top().start_time<<endl;
        thread tempp;
        tempp.index = pq.top().index;
        tempp.start_time = pq.top().start_time + t;
        //the smallest start_out gets popped out
        pq.pop();
        pq.push(tempp);
    }
    
}





