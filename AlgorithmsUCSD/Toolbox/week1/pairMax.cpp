#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
    	cin>>a[i];
     }
    //O(logn) method
    // sort(a.begin(), a.end(), greater<int>());
    // cout<<((long long)a[0])*a[1];
    //(long long)(a[0]*a[1]) will still overflow, must convert one of the number first before multiply

    //O(n) method
    //Use 2 seperate for-loops to find the max 2
     int max1=0, max2=0;
     for(int i=1; i<n; i++){
     	if(a[i]>a[max1])
     		max1 = i;
     }
     //avoid the first number being the largest
     if(max1 == 0)
     	max2=1;
     for(int i=1; i<n; i++){
     	if(i!=max1 && a[i]>a[max2])
     		max2 = i;
     }
     cout<<(long long)a[max1]*a[max2];



     //Alternative O(n):
     //divide into pairs, choose out the bigger ones and the largest one, (n/2)
     //the second largest one is from the bigger array or the other element from that largest pair

     //(n+logn) comparisons:
     //do recursion to find the L and S in that bigger array
     //refer to: https://cs.stackexchange.com/questions/83022/find-largest-and-second-largest-elements-of-the-array/83056#83056
}








