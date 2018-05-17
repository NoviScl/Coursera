#include <iostream>
using namespace std;

const int MAX=100005;
int n;
int votes[MAX];

//solve by divide and conquer
int frequency(int target, int l, int r){
    int count=0;
    for(int i=l; i<=r; i++){
        if(votes[i]==target)
            count++;
    }
    return count;
}

int majority(int l, int r){
    if(l>r) return -1;
    if(l==r)
        return votes[l];
    int k=(r-l+1)/2;
    int left=majority(l, l+k-1);
    int right=majority(l+k, r);
    if(left==right)
        return left;
    int lcount=frequency(left, l, r);
    int rcount=frequency(right, l, r);
    if(lcount>k)
        return left;
    if(rcount>k)
        return right;
    return -1;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>votes[i];
    }
    int ans=majority(0, n-1);
    if(ans==-1)
        cout<<0;
    else
        cout<<1;
}






