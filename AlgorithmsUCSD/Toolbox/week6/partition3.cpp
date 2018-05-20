#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n, values[30], dp[2][601][601], weight=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>values[i];
        weight+=values[i];
    }
    if(weight%3!=0){
        cout<<0;
        return 0;
    }
    else{
        weight/=3;
        //cout<<weight<<endl;
    }
    memset(dp, 0, sizeof(dp));
    dp[1][0][0]=1;
    dp[1][values[1]][0]=1;
    dp[1][0][values[1]]=1;
    for(int i=2; i<=n; i++){
        for(int j=1; j<=weight; j++){
            for(int k=1; k<=weight; k++){
                dp[i%2][j][k]=dp[(i-1)%2][j][k];
                if(j>=values[i])
                    dp[i%2][j][k]+=dp[(i-1)%2][j-values[i]][k];
                if(k>=values[i])
                    dp[i%2][j][k]+=dp[(i-1)%2][j][k-values[i]];
            }
        }
    }
    if(dp[n%2][weight][weight]>0){
        cout<<1;
    }
    else
        cout<<0;
}