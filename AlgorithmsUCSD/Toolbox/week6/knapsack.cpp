#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//simple no-rep knapsack, just value==weight
//to save space, I use a smaller rolling dp matrix
//the downside is that it becomes harder to reconstruct the solution:(
//in this eg, the value=weight of the item(gold)
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
            dp[i%2][w]=dp[(i-1)%2][w]; //without using cur item
            if(w>=gold[i])
                dp[i%2][w]=max(dp[i%2][w], dp[(i-1)%2][w-gold[i]]+gold[i]);
        }
    }
    cout<<dp[n%2][W];
}


//knapsack with repetitions
//each item can take unlimited amount
// int main(){
//     int W, n;
//     int dp[10000]={0}, val[100], weight[100];
//     cin>>W>>n;
//     for(int i=1; i<=n; i++){
//         cin>>val[i]>>weight[i];
//     }
//     memset(dp, 0, sizeof(dp));
//     for(int w=1; w<=W; w++){
//         max_val=0;
//         for(int i=1; i<=n; i++){
//             if(weight[i]<=w){
//                 max_val=max(max_val, dp[w-weight[i]]+val[i]);
//             }
//         }
//         dp[w]=max_val;
//     }
//     cout<<dp[W];
// }

//with repetitions, recursive:
// int knapsack(w){
//     if(dp[w]!=-1)
//         return dp[w];
//     cur_max = 0;
//     for(int i=1; i<=n; i++){
//         if(weight[i]<=w)
//             cur_max = max(cur_max, knapsack(w-weight[i])+value[i]);
//     }
//     dp[w]=cur_max;
//     return dp[w];
// }















