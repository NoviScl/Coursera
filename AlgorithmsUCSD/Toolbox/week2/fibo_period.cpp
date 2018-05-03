#include <iostream>
using namespace std;

typedef unsigned long long ll;

int main(){
    ll n, m, t, fibo[2]={0, 1}, i=2;
    cin>>n>>m;
    while(i<=n){
        fibo[i%2]=(fibo[(i-1)%2]+fibo[(i-2)%2])%m;
        if(fibo[(i-1)%2]==0 && fibo[i%2]==1)
            break;
        i++;
    }
    //in case the period is too long
    if(i>n)
        t=n;
    else
        t=n%(i-1);
    fibo[0]=0;
    fibo[1]=1;
    for(i=2; i<=t; i++){
        fibo[i%2]=(fibo[(i-1)%2]+fibo[(i-2)%2])%m;
    }
    cout<<fibo[t%2];
}