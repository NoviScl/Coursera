#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll fibo_sum(ll n){
    ll t, fibo[2]={0, 1}, i=2, remain, total=1, part=0;
    if(n<=0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    
    while(i<=n){
        fibo[i%2]=(fibo[(i-1)%2]+fibo[(i-2)%2])%10;
        if(fibo[(i-1)%2]==0 && fibo[i%2]==1)
            break;
        i++;
    }
    //indeed the period=60
    t=i-1;
    remain=n%t;
    fibo[0]=0;
    fibo[1]=1;
    for(i=2; i<=min(t, n); i++){
        fibo[i%2]=(fibo[(i-1)%2]+fibo[(i-2)%2])%10;
        total=(total+fibo[i%2])%10;
        if(i==remain)
            part=total;
    }
    return (part+total*(n/t))%10;
}


int main(){
    ll m,n, fm, fn;
    cin>>m>>n;
    fm=fibo_sum(m-1);
    fn=fibo_sum(n);
    if(fn<fm)
        fn+=10;
    cout<<fn-fm;
}




