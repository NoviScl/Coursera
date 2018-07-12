#include <iostream>
#include <unordered_map>
#include <cstring>
#include <utility>	//for pair and make_pair
using namespace std;


int main(){
    unordered_map<int, string> book;
    
    int N, num;
    string op, name;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>op;
        if(op=="add"){
            cin>>num>>name;
            unordered_map<int, string>::iterator iter;
            iter=book.find(num);
            if(iter==book.end()){
                book.insert(make_pair(num, name));
            }
            else{
                iter->second=name;
            }
        }
        else if(op=="find"){
            cin>>num;
            unordered_map<int, string>::iterator iter;
            iter=book.find(num);
            if(iter==book.end()){
                cout<<"not found"<<endl;
            }
            else{
                cout<<iter->second<<endl;
            }
        }
        else if(op=="del"){
            cin>>num;
            book.erase(num);
        }
    }
}
