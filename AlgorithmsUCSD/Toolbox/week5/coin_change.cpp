#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=999999;

int main(){
	int money, coins[3]={1, 3, 4}, cur_min;
	cin>>money;
	int dp[10000]={0};
	for(int i=1; i<=money; i++){
		cur_min = MAX;
		for(int j=0; j<3; j++){
			if(i>=coins[j])
				cur_min=min(cur_min, dp[i-coins[j]]+1);
		}
		dp[i]=cur_min;
	}
	cout<<dp[money];
}