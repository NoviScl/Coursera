#include <iostream>
using namespace std;

//find >1/3n major element
int boyer_moore(){
	//at most exist 2 such major elements
	int cand1, cand2, count1=0, count2=0;
	for(int i=0; i<n; i++){
		if(count1==0)
			cand1 = votes[i];
		if(count2==0)
			cand2 = votes[i];
		if(votes[i]==cand1)
			count1++;
		else
			count1--;
		if(votes[i]==cand2)
			count2++;
		else
			count2--;
	}
	count1=0, count2=0;
	for(int i=0; i<n; i++){
		if(votes[i]==cand1)
			count1++;
		if(votes[i]==cand2)
			count2++;
	}
	if(count1>int(n/3))
		cout<<cand1;
	if(count2>int(n/3))
		cout<<cand2;
}


//Boyer Moore:
//Every time remove a different pair,
//if there is a major value, it will be the candidate
//but need to check because even if no major element, candidate will still have some value
int main(){
    int n, votes[100005], count=0, candidate=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>votes[i];
    }
    for(int i=0; i<n; i++){
        if(count==0){
            candidate = votes[i];
        }
        if(votes[i]==candidate){
            count++;
        }
        else
            count--;
    }
    count=0;
    for(int i=0; i<n; i++){
        if(votes[i]==candidate)
            count++;
    }
    if(count>int(n/2))
        cout<<1;
    else
        cout<<0;
}


