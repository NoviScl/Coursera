#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
const int MAX=1000000;
struct packet{
    int start, duration, index;
};

int start[MAX]={0};
int main(){
    deque<packet> buffer;
    int cur_start_time=0, n, S;
    packet temp;
    cin>>S>>n;
    
    //get all input and store into the stack first
    for(int i=0; i<n; i++){
        cin>>temp.start>>temp.duration;
        temp.index=i;
        //empty stack, just go in
        if(buffer.size()==0){
            cur_start_time = temp.start;
            buffer.push_back(temp);
        }
        else{
            //process the previous one
            //else later need to check this can put in or not
            if(cur_start_time + buffer.front().duration<=temp.start){
                start[buffer.front().index] = cur_start_time;
                cur_start_time += buffer.front().duration;
                buffer.pop_front();
                buffer.push_back(temp);
                cur_start_time = max(cur_start_time, buffer.front().start);
            }
            else{
                //have not finished precessing front yet
                if(buffer.size()<S)
                    buffer.push_back(temp);
                else
                    start[temp.index] = -1;
            }
        }
    }
    while(!buffer.empty()){
        if(buffer.size()==1){
            start[buffer.front().index] = cur_start_time;
            buffer.pop_front();
        }
        else{
            packet t = buffer.front();
            buffer.pop_front();
            start[t.index]=cur_start_time;
            if(cur_start_time+t.duration>buffer.front().start){
                cur_start_time = cur_start_time + t.duration;
            }
            else{
                cur_start_time=buffer.front().start;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        cout<<start[i]<<endl;
    }
}







