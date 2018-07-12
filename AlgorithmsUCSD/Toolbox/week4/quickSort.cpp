#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

//inspired by: https://www.jianshu.com/p/d70aeccaee19
void partition2(vector<int> &a, int l, int r, int &m1, int &m2) {
  int pivot = a[l];
  int lt = l, gt = r;	//before lt: all less than pivot, after gt: all greater than pivot
  //in the process:
  //lt: the leftmost element in the equal chunk, 
  //gt: one element before the gt chunk
  int i=l+1;
  while(i<=gt){
  	if(a[i]<pivot){
  		swap(a[lt], a[i]);
  		i++;
  		lt++;
  	}
  	else if(a[i]>pivot){
  		swap(a[i], a[gt]);
  		gt--;
  	}
  	else
  		i++;
  }
  m1 = lt;
  m2 = gt;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  int m1, m2;
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  //so that the first element is the pivot
  partition2(a, l, r, m1, m2);

  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
}
