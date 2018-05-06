#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, i=1, count=0;
	vector<int> candy;
	cin>>n;
	while(n>=i){
		n -= i;
		candy.push_back(i);
		count++;
		i++;
	}
	candy[candy.size()-1]+=n;
	cout<<candy.size()<<endl;
	for(int i=0; i<candy.size(); i++){
		cout<<candy[i]<<' ';
	}
}