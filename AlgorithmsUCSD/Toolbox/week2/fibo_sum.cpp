#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;

int main(){
    ll n, t, fibo[2]={0, 1}, i=2, remain, total=1, part=0;
    cin>>n;

    if(n==0){
    	cout<<0;
    	return 0;
    }
    else if(n==1){
    	cout<<1;
    	return 0;
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
    cout<<(part+total*(n/t))%10;
}




