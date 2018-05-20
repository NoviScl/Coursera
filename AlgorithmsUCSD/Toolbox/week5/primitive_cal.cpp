#include <iostream>
#include <algorithm>
using namespace std;

void print_steps(int cur, int prev_step[]){
    if(cur==1){
        cout<<1;
        return;
    }
    print_steps(prev_step[cur], prev_step);
    cout<<' '<<cur;
}

int main(){
    int goal;
    cin>>goal;
    int dp[1000005]={0, 0};
    int prev_step[1000005]={0, 0};
    for(int i=2; i<=goal; i++){
        dp[i]=dp[i-1]+1;
        prev_step[i] = i-1;
        if(i%2==0 && dp[i]>dp[i/2]+1){
            dp[i] = dp[i/2]+1;
            prev_step[i]=i/2;
        }
        if(i%3==0 && dp[i]>dp[i/3]+1){
            dp[i] = dp[i/3]+1;
            prev_step[i] = i/3;
        }
    }
    cout<<dp[goal]<<endl;
    print_steps(goal, prev_step);
}