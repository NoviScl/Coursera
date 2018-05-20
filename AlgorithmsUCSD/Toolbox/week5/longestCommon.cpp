#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	int m, n, cur_max;
	int dp[105][105]={0}, A[105]={0}, B[105]={0};
	cin>>m;
	for(int i=1; i<=m; i++){
		cin>>A[i];
	}
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>B[i];
	}
	for(int i=1; i<=max(m, n); i++){
		dp[i][0]=0;
		dp[0][i]=0;
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			cur_max=max(dp[i-1][j], dp[i][j-1]);
			if(A[i]==B[j])
				cur_max=max(cur_max, dp[i-1][j-1]+1);
			//don't need to check for the last case
			dp[i][j]=cur_max;
		}
	}
	cout<<dp[m][n];
}