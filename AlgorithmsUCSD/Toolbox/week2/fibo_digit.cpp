#include <iostream>
using namespace std;


int main(){
	int fibo[2]={0,1}, n;
	cin>>n;
	for(int i=2; i<=n; i++){
		fibo[i%2]=(fibo[i%2]+fibo[(i+1)%2])%10;
	}
	cout<<fibo[n%2];
}