#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

struct item{
	int value, weight;
	double ratio;
};

bool cmp(item a, item b){
	return a.ratio > b.ratio;
}

int main(){
	int n, W=0, a;
	double result=0;
	vector<item> items;
	item temp;
	cin>>n>>W;
	for(int i=0; i<n; i++){
		cin>>temp.value;
		cin>>temp.weight;
		temp.ratio = double(temp.value)/temp.weight;
		items.push_back(temp);
	}

	sort(items.begin(), items.end(), cmp);


	cout<<fixed<<setprecision(4);
	for(int i=0; i<n; i++){
		if(W==0)
			break;

		a=min(items[i].weight, W);
		result += double(a)/items[i].weight*items[i].value;
		W -= a;
	}
	cout<<result;
}















