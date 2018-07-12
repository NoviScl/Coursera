#include <iostream>
#include <set>
using namespace std;

typedef long long ll;
ll x = 0;
ll M = 1000000001;

int main(){
    set<ll> T;
    
    ll n, num1, num2, result;
    char op;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>op;
        if(op=='+'){
            cin>>num1;
            T.insert((num1+x)%M);
        }
        else if(op=='-'){
            cin>>num1;
            T.erase((num1+x)%M);
        }
        else if(op=='?'){
            cin>>num1;
            if(T.find((num1+x)%M)==T.end())
                cout<<"Not found"<<endl;
            else
                cout<<"Found"<<endl;
        }
        else{
            cin>>num1>>num2;
            result = 0;
            for(auto it=T.lower_bound((num1+x)%M); it!=T.end() && it!=T.upper_bound((num2+x)%M); it++){
                result += (*it);
            }
            x = result;
            cout<<x<<endl;
        }
    }
}


//15
//? 1
//+ 1
//? 1
//+ 2
//s 1 2
//+ 1000000000
//? 1000000000
//- 1000000000
//? 1000000000
//s 999999999 1000000000
//- 2
//? 2
//- 0
//+ 9
//s 0 9
