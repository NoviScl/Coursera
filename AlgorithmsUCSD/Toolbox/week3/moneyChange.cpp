#include <iostream>
using namespace std;

int main(){
	int m, count=0;
	cin>>m;
	count += m/10;
	m = m%10;
	count += m/5;
	m = m%5;
	count += m;
	cout<<count;
}