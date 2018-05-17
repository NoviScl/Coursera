#include <iostream>
#include <algorithm>
using namespace std;

//O(nlogn)
int main(){
	int n;
	long long votes[100005];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>votes[i];
	}
	sort(votes, votes+n);
	int mid = votes[int(n/2)], count=0;
	for(int i=0; i<; i++){
		if(votes[i]==mid)
			count++;
	}
	if(count>int(n/2))
		cout<<1;
	else
		cout<<0;
}