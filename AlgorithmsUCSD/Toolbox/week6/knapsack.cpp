#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//simple no-rep knapsack, just value==weight
//to save space, I use a smaller rolling dp matrix
//the downside is that it becomes harder to reconstruct the solution:(
int main(){
    int W, n;
    cin>>W>>n;
    int gold[400]={0};
    for(int i=1; i<=n; i++){
        cin>>gold[i];
    }
    int dp[2][10090];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int w=1; w<=W; w++){
            dp[i%2][w]=dp[(i-1)%2][w];
            if(w>=gold[i])
                dp[i%2][w]=max(dp[i%2][w], dp[(i-1)%2][w-gold[i]]+gold[i]);
        }
    }
    cout<<dp[n%2][W];
}