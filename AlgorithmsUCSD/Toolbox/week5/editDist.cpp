#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string first, second;
    int cur_min;
    cin>>first>>second;
    int dp[105][105]={0};
    int len_a = first.length(), len_b = second.length();
    for(int i=1; i<=max(len_a, len_b); i++){
        dp[i][0]=i;
        dp[0][i]=i;
    }
    for(int i=1; i<=len_a; i++){
        for(int j=1; j<=len_b; j++){
            //insertion and deletion
            cur_min = min(dp[i-1][j]+1, dp[i][j-1]+1);
            //match or mismatch
            if(first[i-1]==second[j-1])
                cur_min=min(cur_min, dp[i-1][j-1]);
            else
                cur_min=min(cur_min, dp[i-1][j-1]+1);
            dp[i][j]=cur_min;
        }
    }
    cout<<dp[len_a][len_b];
}
