#include <iostream>
using namespace std;

typedef pair<int, int> p;

int main(){
    string buffer;
    cin>>buffer;
    
    p stack[100050];
    int top=-1;
    
    for(int i=0; i<buffer.length(); i++){
        if(buffer[i]== '(' || buffer[i]=='[' || buffer[i]=='{'){
            top++;
            stack[top].second = buffer[i];
            stack[top].first = i;
        }
        else if(buffer[i]==')' && stack[top].second=='('){
            top--;
        }
        else if(buffer[i]==']' && stack[top].second=='[')
            top--;
        else if(buffer[i]=='}' && stack[top].second=='{')
            top--;
        else if(buffer[i]==')' || buffer[i]==']' || buffer[i]=='}'){
            cout<<(i+1);
            return 0;
        }
    }
    if(top<0){
        cout<<"Success";
        return 0;
    }
   	// while(top>0){
    //     top--;
   	// }
   	// cout<<(stack[top].first+1);
    cout<<(stack[0].first+1); //the first unclosed bracket
}

