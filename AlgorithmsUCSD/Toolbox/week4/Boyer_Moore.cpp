#include <iostream>
using namespace std;

// Finds all elements that appears more than "nums.size() / k" times,
//at most k-1 such numbers
//intuition: if exist majority, confirm will be left out after canceling, 
//but non-majority may also cancel each other, so need to check again the occurrences
vector<int> findRepeatedElements(vector<int>& nums, int k) {
    unordered_map<int, int> counters;
    unordered_map<int, int> occurrences;
    for (auto n: nums) {
        occurrences[n]++;
        
        // maintains k-1 counters at most
        if (counters.size() < k - 1 || counters.count(n)) {
            counters[n]++;
        } else {
            // decrease all counters by 1
            // remove 0 values
            auto it = counters.begin();
            while (it != counters.end()) {
                if (it->second == 1) {
                    it = counters.erase(it);
                } else {
                    counters[it->first]--;
                    it++;
                }
            }
        }
    }
    
    // second pass
    vector<int> result;
    for (auto pair: counters) {
        if (occurrences[pair.first] > nums.size() / k) {
            result.push_back(pair.first);
        }
    }
    return result;
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


    //testing for generalised case
 //    vector<int> nums1 = {1, 2, 3, 4, 1, 1, 3, 3};
	// vector<int> nums2 = {1, 2, 3, 4, 5, 6};

	// // 3 and 1 are majority elements
	// auto result = findRepeatedElements(nums1, 4);
	// for (auto n: result) {
 //    	cout << n << " ";
	// }
	// cout << endl;

	// // No majority element in nums2
	// result = findRepeatedElements(nums2, 3);
	// for (auto n: result) {
 //    	cout << n << " ";
	// }
	// cout << endl;
}


