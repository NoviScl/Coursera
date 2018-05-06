#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string a, string b){
	// this is a smart way to compare two numbers with different lengths
	//it helps to decide which number to put first to max the overall result
	return a+b > b+a;
}

int main(){
	int n;
	cin>>n;
	vector<string> num(n);
	for(int i=0; i<n; i++){
		cin>>num[i];
	}
	sort(num.begin(), num.end(), cmp);

	string result;
	for(int i=0; i<n; i++){
		result+=num[i];
	}
	cout<<result;
}