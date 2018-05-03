#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll GCD(ll a, ll b){
	ll temp;
	if(a<b){
		swap(a, b);
	}
	while(b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

int main(){
	ll a, b, gcd;
	cin>>a>>b;
	gcd=GCD(a, b);
	cout<<(a/gcd)*b;
}