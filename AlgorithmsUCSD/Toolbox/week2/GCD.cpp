#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long a, b, temp;
	cin>>a>>b;
	if(a<b){
		swap(a, b);
	}
	while(b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	cout<<a;
}