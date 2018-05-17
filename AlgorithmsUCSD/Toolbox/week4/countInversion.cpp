#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int N;

ll mergeSort(vector<ll> &a){
    int n = a.size();
    if(n<=1)
        return 0;
    int mid = n/2;
    vector<ll> left(a.begin(), a.begin()+mid);
    vector<ll> right(a.begin()+mid, a.end());
    ll l_inv = mergeSort(left);
    ll r_inv = mergeSort(right);
    ll num_inv=l_inv+ r_inv;
    //merge
    int i=0, l=0, r=0;
    while(l<left.size() && r<right.size()){
        if(left[l]<=right[r]){
            a[i] = left[l];
            i++;
            l++;
        }
        else{
            //deal with inversions
            num_inv+=(left.size()-l);
            a[i]=right[r];
            i++;
            r++;
        }
    }
    
    while(l<left.size()){
        a[i]=left[l];
        i++;
        l++;
    }
    while(r<right.size()){
        a[i]=right[r];
        i++;
        r++;
    }
    return num_inv;
}

int main() {
    cin>>N;
    vector<ll> num(N);
    for(int i=0; i<N; i++){
        cin>>num[i];
    }
    cout<<mergeSort(num)<<endl;
}
