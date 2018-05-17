#include <iostream>
#include <algorithm>
using namespace std;

unsigned int nums[100000], n;
// int bSearch(int target, int l, int r){
// 	if(l>r){
// 		return -1;
// 	}
// 	int mid = l+(r-l)/2;
// 	if(nums[mid]==target){
// 		return mid;
// 	}
// 	else if(nums[mid]>target){
// 		return bSearch(target, l, mid-1);
// 	}
// 	else{
// 		return bSearch(target, mid+1, r);
// 	}
// }
int bSearch(int target){
	int l=0, r=n-1, mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(nums[mid]==target)
			return mid;
		else if(nums[mid]<target)
			l=mid+1;
		else
			r=mid-1;
	}
	return -1;
}

int main(){
	int k, t;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>nums[i];
	}
	sort(nums, nums+n);
	cin>>k;
	for(int i=0; i<k; i++){
		cin>>t;
		cout<<bSearch(t)<<' ';
	}
}
