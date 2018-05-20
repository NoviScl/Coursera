#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n,m,l, cur_max;
	int dp[105][105][105];
	int A[105], B[105], C[105];
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>A[i];
	}
	cin>>m;
	for(int i=1; i<=m; i++){
		cin>>B[i];
	}
	cin>>l;
	for(int i=1; i<=l; i++){
		cin>>C[i];
	}
	memset(dp, 0, sizeof(dp));
	for(int ni=1; ni<=n; ni++){
		for(int mi=1; mi<=m; mi++){
			for(int li=1; li<=l; li++){
				cur_max=max(dp[ni-1][mi][li], dp[ni][mi-1][li]);
				cur_max=max(cur_max, dp[ni][mi][li-1]);
				if(A[ni]==B[mi] && A[ni]==C[li])
					cur_max=max(cur_max, dp[ni-1][mi-1][li-1]+1);
				dp[ni][mi][li]=cur_max;
			}
		}
	}
	cout<<dp[n][m][l];
}







