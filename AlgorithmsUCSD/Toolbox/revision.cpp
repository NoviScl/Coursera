#include <iostream>
using namespace std;

int main(){
	int fib[2]={0, 1}, n;
	cin>>n;
	for(int i=2; i<=n; i++){
		fibo[i%2]=(fibo[i%2]+fibo[(i+1)%2])%10;
	}
	cout<<fibo[n%2];
}

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long a, b, temp;
	cin>>a>>b;
	if(a<b)
		swap(a,b);
	while(b!=0){
		temp = a%b;
		a = b;
		b = temp;
	}
	cout<<a;
}

typedef long long ll;

ll GCD(ll a, ll b){
	ll temp;
	if(a<b)
		swap(a, b);
	while(b!=0){
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

int main(){
	ll a, b, gcd;
	cin>>a>>b;
	gcd = GCD(a, b);
	cout<<(a/gcd)*b;
}

int main(){
	int n, fibo[2]={0, 1};
	cin>>n;
	for(int i=2; i<=n; i++){
		fibo[i%2] = fibo[i%2] + fibo[(i+1)%2];
	}
	cout<<fibo[n];
}

typedef unsigned long long ll;

int main(){
	ll n, m, t, fibo[2]={0, 1}, i=2;
	cin>>n>>m;
	while(i<=n){
		fibo[i%2] = (fibo[(i-1)%2] + fibo[(i-2)%2])%m;
		if(fibo[(i-1)%2]==0 && fibo[i%2]==1)
			break;
		i++;
	}
	if(i>n)
		t = n;
	else
		t = n%(i-1);
	fibo[0] = 0;
	fibo[1] = 1;
	 for(i=2; i<=t; i++)
	 	fibo[i%2] = (fibo[(i-1)%2]+fibo[(i-2)%2])%m;
	 cout<<fibo[t%2];
}

int main(){
	ll n, t, fibo[2]={0, 1}, i=2, remain, total=1, part=0;
	
	if(n==0){
		cout<<0;
		return 0;
	}
	else if(n==1){
		cout<<1;
		return 0;
	}

	while(i<=n){
		fibo[i%2] = (fibo[(i-1)%2]+fibo[(i-2)%2])%10;
		if(fibo[(i-1)%2]==0 && fibo[i%2]==1)
			break;
		i++;
	}

	t = i-1;
	remain = n%t;
	fibo[0] = 0;
	fibo[1] = 1;
	for(i=2; i<=min(t, n); i++){
		fibo[i%2] = (fibo[(i-1)%2] + fibo[(i-1)%2])%10;
		total = (total+fibo[i%2])%10;
		if (i==remain)
			part = total;
	}
	cout<<(part+total*(n/t))%10;
}


int main(){
	int m, count = 0;
	cin>>m;
	count += m/10;
	m = m%10;
	count += m/5;
	m = m%5;
	count += m;
	cout<<count;
}

struct item{
	int value, weight;
	double ratio;
};

bool cmp(item a, item b){
	return a.ratio > b.ratio;
}

int main(){
	int n, W=0, a;
	double result = 0;
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
		a = min(items[i].weight, W);
		result += double(a)/items[i].weight*items[i].value;
		W -= a;
	}
	cout<<result;
}


long long max_dot_product(vertor<int> a, vector<int> b){
	long long result = 0;
	for(size_t i = 0; i<a.size(); i++){
		result += ((long long)a[i]) * b[i];
	}
	return result;
}


int main(){
	size_t n;
	cin>>n;
	vector<int> a(n), b(n);
	for(size_t i=0; i,n; i++){
		cin>>a[i];
	}
	for(size_t i=9)

		sort(a.begin(), a.end(), greater<int>());
}


struct Segment{
	int start, end;
};

bool cmp(Segment a, Segment b){
	return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments){
	vector<int> points;
	int cur_point = segments[0].end;
	points.push_back(cur_point);
	for(size_t i=1; i<segments.size(); i++){
		if(segments[i].start > cur_point){
			cur_point = segments[i].end;
			points.push_back(cur_point);
		}
	}
	return points;
}


struct Segment{
	int start, end;
};

bool cmp(Segment a, Segment b){
	return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments){
	vector<int> points;
	int cur_point;
	points.push_back(cur_point);
	for(size_t i=1; i<segments.size(); i++){
		if(segments[i].start>cur_point.start){
			cur_point = segments[i].end;
			points.push_back(cur_point);
		}
	}
	return points;
}

int main(){
	int n;
	cin>>n;
	vector<Segment> segments(n);
	for(size_t i=0; i<n; i++){
		cin>>segments[i].start>>segments[i].end;
	}
	sort(segments.begin(), segments.end(), cmp);
	vector<int> points = optimal_points(segments);
	for(size_t i=0; i<points.size(); i++){
		cout<<points[i]<<" ";
	}
}

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
	candy[candy.size()-1] += n;
	cout<<candy.size()<<endl;
	for(int i=0; i<candy.size(); i++){
		cout<<candy[i]<<' ';
	}
}

bool cmp(string a, string b){
	return a+b > b+a;
}

int main(){
	int n;
	cin>>n;
	vector<string> num(n);
	for(int i=0; i<n; i++){
		cin>>num[i];
	}
	sort(num.begin(), num.end(), cmp);
	string result;
	for(int i=0; i<n; i++){
		result += num[i];
	}
	cout<<result;
}

bool cmp(string a, string b){
	return a+b > b+a;
}



unsigned int nums[100000], n;

int bSearch(int target, int l, int r){
	if(l>r)
		return -1;
	int mid = l+(r-l)/2;
	if(nums[mid]==target)
		return mid;
	else if(nums[mid]>target)
		return bSearch(target, l, mid-1);
	else
		return bSearch(target, mid+1, r);
}

int bSearch(int target){
	int l=0, r=n-1, mid;
	while(l<=r){
		mid = l+(r-l)/2;
		if(nums[mid]==target)
			return mid;
		else if(nums[mid]<target)
			l = mid+1;
		else
			r = mid-1;
	}
	return -1;
}


int main(){
	int n;
	long long votes[10005];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>votes[i];
	}
	sort(votes, votes+n);
	int mid = votes[int(n/2)], count = 0;
	for(int i=0; i<n; i++){
		if(votes[i]==mid)
			count++;
	}
	if(count>int(n/2))
		cout<<1;
	else
		cout<<0;
}


const int MAX = 100005;
int n;
int votes[MAX];

int frequency(int target, int l, int r){
	int count=0;
	for(int i=l; i<r; i++){
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
	int left = majority(l, l+k-1);
	int right = majority(l+k, r);
	if(left==right)
		return left;
	int lcount = frequency(left, l, r);
	int rcount = frequency(right, l, r);
	if(lcount>k)
		return left;
	else if(rcount>k)
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


int majority(int l, int r){
	if(l>r) return -1;
	if(l==r) 
		return votes[l];
	int k=(r-l+1)/2;
	int left = majority(l, l+k-1);
	int right = majority(l+k, r);
	if(left == right)
		return left;
	int lcount = frequency(left, l, r);
	int rcount = frequency(right, l, r);
	if(lcount>k)
		return left;
	if(rcount>k)
		return right;
	return -1;
}


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
		if(votes[i]==candidate)
			count++;
		else
			count--;
	}
	count = 0;
	for(int i=0; i<n; i++){
		if(votes[i]==candidate)
			count++;
	}
	if(count>int(n/2))
		cout<<1;
	else
		cout<<0;
}


int boyer_moore(){
	int cand1, cand2, count1=0, count1=0;
	for(int i=0; i<n; i++){
		if(count1==0)
			cand1 = votes[i];
		if(count2==0)
			cand2 = votes[i];
		if(votes[i]==cand1)
			count++;

	}
}


//Find all elements that appear more than nums.size()/k times,
//at most k-1 such numbers
vector<int> findRepeatedElements(vector<int> &nums, int k){
	unordered_map<int, int> counters;
	unordered_map<int, int> occurrences;
	for(auto n: nums){
		occurrences[n]++;

		//maintains k-1 counters at most
		if(counter.size()<k-1 || counters.count(n)){
			counters[n]++;
		}
		else{
			//decrease all counters by 1
			//remove 0 values
			auto it = counters.begin();
			while(it !=  counters.end()){
				if(it->second == 1)
					it = counters.erase(it);
				else{
					counters[it->first]--;
					it++;
				}
			}
		}
	}

	vector<int> result;
	for(auto pair: counters){
		if(occurrences[pair.first] . nums.size()/k){
			result.push_back(pair.first);
		}
	}
	return result;
}


vector<int> findRepeatedElements(vector<int> &nums, int k){
	unordered_map<int, int> counters;
	unordered_map<int, int> occurrences;
	for(auto n: nums){
		occurrences[n]++;

		//maintains k-1 counters at most
		if(counters.size()<k-1 || counters.find(n)){
			counters[n]++;
		}
		else{
			//decrease all counters by 1
			//remove 0 values
			auto it = counters.begin();
			while(it != counters.end()){
				if(it->second==1){
					it=counters.erase(it);
				}
				else{
					counters[it->first]--;
					it++;
				}
			}
		}
	}

	vector<int> result;
	for(auto pair: counters){
		if(occurences[pair.first]>nums.size()/k){
			result.push_back(pair.first);
		}
	}
	return result;
}


int main(){
	vector<int> nums1 = {};
	vector<int> nums2 = {};

	auto result = findRepeatedElements(nums1, 4);
	for(auto n: result){
		cout<<n<<" ";
	}
	cout<<endl;

	result = findRepeatedElements(nums2, 3);
	for(auto n: result){
		cout<<n<<' ';
	}
	cout<<endl;
}


vector<int> findRepeatedElements(vector<int> &nums, int k){
	unordered_map<int, int> counters;
	unordered_map<int, int> occurrences;
	for(auto n: nums){
		occurrences[n]++;

		if(counters.size()<k-1 || counetrs.count(n)){
			counters[n]++;
		}
		else{
			auto it = counters.begin();
			while(it != counters.end()){
				if(it->second==1){
					it = counters.erase(it);
				}
				else{
					counters[it->first]--;
					it++;
				}
			}
		}
	}

	vector<int> result;
	for(auto pair: counters){
		if(occurrences[pair.first] > nums.size()/k){
			result.push_back(pair.first);
		}
	}
	return result;
}


#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void partition2(vector<int> &a, int l , int r, int &m1, int &m2){
	int pivot = a[l];
	int lt = l, gt = r;
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

void partition2(vector<int> &a, int l, int r, int &m1, int &m2){
	int pivot = a[l];
	int lt=l, gt=r;
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

void partition2(vector<int> &a, int l, int r, int &m1, int &m2){
	int pivot = a[l];
	int lt=l, gt=r;
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

void randomized_quick_sort(vector<int> &a, int l, int r){
	if(l>=r)
		return;
	int m1, m2;
	int k = l + rand()%(r-l+1);
	swap(a[l], a[k]);
	partition2(a, l, r, m1, m2);
	randomized_quick_sort(a, l, m1-1);
	randomized_quick_sort(a, m2+1, r);
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(size_t i=0; i<a.size(); i++){
		cin>>a[i];
	}
	randomized_quick_sort(a, 0, a.size()-1);
	for(size_t i=0; i<a.size(); i++){
		cout<<a[i]<<' ';
	}
}


typedef long long ll;
int N;

ll mergeSort(vector<ll> &a){
	int n=a.size();
	if(n<=1)
		return 0;
	int mid = n/2;
	vector<ll> left(a.begin(), a.begin()+mid);
	vector<ll> right(a.begin()+mid, a.end());

	ll l_inv = mergeSort(left);
	ll r_inv = mergeSort(right);
	ll num_inv = l_inv+r_inv;

	//merge
	int i=0, l=0, r=0;
	while(l<left.size() && r<right.size()){
		if(left[l]<=right[r]){
			a[i] = left[l];
			i++;
			l++;
		}
		else{
			num_inv+=(left.size()-l);
			a[i] = right[r];
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


ll mergeSort(vector<ll> &a){
	int n = a.size();
	if(n<=1)
		return 0;
	int mid = n/2;
	vector<ll> left(a.begin(), a.begin()+mid);
	vector<ll> right(a.begin()+mid, a.end());
	ll l_inv = mergeSort(left);
	ll r_inv = mergeSort(right);
	ll num_inv = l_inv + r_inv;

	int i=0, l=0, r=0;
	while(l<left.size()&&r<right.size()){
		if(left[l]<=right[r]){
			a[i] = left[l];
			i++;
			l++;
		}
		else{
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

int main(){
	cin>>N;
	vector<ll> num(N);
	for(int i=0; i<N; i++){
		cin>>num[i];
	}
	cout<<mergeSort(num)<<endl;
}



const int MAX=99999;
struct point{
	int pos;
	int types; //1:close, 2: query, 3: open
	int index=MAX;
	int cover=-1;
};

void sweep_line(vector<point> &data){
	int count=0;
	for(int i=0; i<data.size(); i++){
		if(data[i].types=2)
			data[i].cover=count;
		else if(data[i].types=1)
			count--;
		else
			count++;
	}
}

bool cmp1(point a, point b){
	if(a.pos==b.pos)
		return a.types > b.types;
	return a.pos<b.pos;
}

bool cmp2(point a, point b){
	return a.index < b.index;
}

int main(){
	int n, m;
	point temp;
	cin>>n>>m;
	vector<point> data;
	for(size_t i=0; i<n; i++){
		cin>>temp.pos;
		temp.types=3;
		data.push_back(temp);
		cin>>temp.pos;
		temp.types=1;
		data.push_back(temp);
	}
	for(int i=0; i<m; i++){
		cin>>temp.pos;
		temp.index=i;
		temp.types=2;
		data.push_back(temp);
	}
	sort(data.begin(), data.end(), cmp1);
	sweep_line(data);
	sort(data.begin(), data.end(), cmp2);
	for(size_t i=0; i<m; i++){
		cout<<data[i].cover<<' ';
	}
}

const int MAX=99999;
struct point{
	int pos;
	int types;
	int index=MAX;
	int cover=-1;
};

void sweep_line(vector<point> &data){
	int count=0;
	for(int i=0; i<data.size(); i++){
		if(data[i].types==2)
			data[i].cover=count;
		else if(data[i].types==1)
			count--;
		else
			count++;
	}
}

bool cmp1(point a, point b){
	if(a.pos==b.pos)
		return a.types>b.types;
	return a.pos < b.pos;
}

bool cmp2(point a, point b){
	return a.index < b.index;
}

int main(){
	int n, m;
	point temp;
	cin >> n >> m;
	vector<point> data;
	for(size_t i=0; i<n; i++){
		cin>>temp.pos;
		temp.types=3;
		data.push_back(temp);
		cin>>temp.pos;
		temp.types=1;
		temp.push_back(temp);
	}
	for(int i=0; i<m; i++){
		cin>>temp.pos;
		temp.index=i;
		temp.types=2;
		data.push_back(temp);
	}

	sort(data.begin(), data.end(), cmp1);
	sweep_line(data);
	sort(data.begin(), data.end(), cmp2);
	for(size_t i=0; i<m; i++)
		cout<<data[i].cover<<' ';
}


double MAX=99999.9
struct point{
	int x, y;
};

bool compareX(point a, point b){
	if(a.x==b.x)
		return a.y < b.y;
	return a.x < b.x;
}

bool compareY(point a, point b){
	if(a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

double dist(point a, point b){
	return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
}

double brute_force(vector<point> P){
	int n = P.size();
	double MIN = MAX;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(dist(P[i], P[j])<MIN)
				MIN = dist(P[i], P[j]);
		}
	}
	return MIN;
}

double stripClosest(vector<point> Pstrip, double d){
	int n = Pstrip.size();
	double best = d;
	sort(Pstrip.begin(), Pstrip.end(), compareY);
	for(int i=0; i<n; i++){
		for(int j=1; j<min(7, n-1-i); j++){
			if(dist(Pstrip[i], Pstrip[i+j])<best){
				best = dist(Pstrip[i], Pstrip[i+j]);
			}
		}
	}
	return best;
}


double closestPair(vector<point> P){
	int n = P.size();
	if(n<=3)
		return brute_force(P);
	int mid = n/2;
	point midP = P[mid];

	vector<point> Left(P.begin(), P.begin()+mid);
	vector<point> Right(P.begin()+mid, P.end());
	double dl = cloestPair(Left);
	double dr = cloestPair(Right);

	double best = min(dl, dr);

	vector<point> Pstrip;
	for(int i=0; i<n; i++){
		if(abs(P[i].x - midP.x)<best){
			Pstrip.push_back(P[i]);
		}
	}
	return min(best, stripClosest(Pstrip, best));
}

int main(){
	int N;
	point temp;
	cin>>N;
	vector<point> Px;
	for(int i=0; i<N; i++){
		cin>>temp.x>>temp.y;
		Px.push_back(temp);
	}
	sort(Px.begin(), Py.begin(), compareX);
	cout<<fixed;
	cout<<setprecision(9)<<double(cloestPair(Px))<<endl;
}


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double MAX=999999.9;
struct point{
	int x, y;
};

bool compareX(point a, point b){
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

bool compareY(point a, point b){
	if(a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

double dist(point a, point b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

double brute_force(vector<point> P){
	int n = P.size();
	double MIN = MAX;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(dist(P[i], P[j])<MIN)
				MIN = dist(P[i], P[j]);
		}
	}
	return MIN;
}

double stripClosest(vector<point> Pstrip, double d){
	int n = Pstrip.size();
	double best = d;
	sort(Pstrip.begin(), Pstrip.end(), compareY);
	for(int i=0; i<n; i++){
		for(int j=1; j<=min(7, n-1-i); j++){
			if(dist(Pstrip[i], Pstrip[i+j])<best)
				best = dist(Pstrip[i], Pstrip[i+j]);
		}
	}
	return best;
}

double cloesetPair(vector<point> P){
	int n = P.size();
	if(n<=3)
		return brute_force(P);
	int mid = n/2;
	point midP = P[mid];

	vector<point> Left(P.begin(), P.begin()+mid);
	vector<point> Right(P.begin()+mid, P.end());
	double dl = closestPair(Left);
	double dr = closestPair(Right);

	double best = min(dl, dr);
	vector<point> Pstrip;
	for(int i=0; i<n; i++){
		if(abs(P[i].x-midP.x)<best)
			Pstrip.push_back(P[i]);
	}
	return min(best, stripClosest(Pstrip, best));
}


int main(){
	int N;
	point temp;
	cin>>N;
	vector<point> Px;
	for(int i=0; i<N; i++){
		cin>>temp.x>>temp.y;
		Px.push_back(temp);
	}
	sort(Px.begin(), Px.end(), compareX);
	cout<<fixed;
	cout<<setprecision(9)<<double(cloestPair(Px))<<endl;
}


double stripClosest(vector<point> Pstrip, double d){
	int n=Pstrip.size();
	double best = d;
	for(int i=0; i<n; i++){
		for(int j=1; j<min(7, n-1-i); j++)
			best = dist(Pstrip[i], Pstrip[i+j]);
	}
	return best
}

double cloestPair(vector<point> Px, vector<point> Py){
	int n = Px.size();
	if(n<=3)
		return brute_force(Px);
	int mid = n/2;
	point midP = Px[mid];

	vector<point> Pyl;
	vector<point> Pyr;

	for(int i=0; i<n; i++){
		if(Py[i].x < midP.x || (Py[i].x==midP.x && Py[i].y<midP.y))
			Pyl.push_back(Py[i]);
		else
			Pyr.push_back(Py[i]);
	}

	vector<point> Left(Px.begin(), Px.begin()+mid);
	vector<point> Right(Px.begin()+mid+1, Px.end());
	double dl = closestPair(Left, Pyl);
	double dr = closestPair(Right, Pyr);

	double best = min(dl, dr);

	vector<point> Pstrip;
	for(int i=0; i<n; i++){
		if(abs(Py[i].x-midP.x)<best)
			Pstrip.push_back(Py[i]);
	}
	return min(best, stripClosest(Pstrip, best));
}


#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 999999;

int main(){
	int money, coins[3]={1, 3, 4}, cur_min;
	cin>>money;
	int dp[10000] = {0};
	for(int i=1; i<=money; i++){
		cur_min = MAX;
		for(int j=0; j<3; j++){
			if(i>=coins[j])
				cur_min = min(cur_min, dp[i-coins[j]]+1);
		}
		dp[i] = cur_min;
	}
	cout<<dp[money];
}

const int MAX = 999999;
int main(){
	int money, coins[3]={1,3,4}, cur_min;
	cin>>money;
	int dp[10000]={0};
	for(int i=1; i<=money; i++){
		cur_min = MAX;
		for(int j=0; j<3; j++){
			if(i>=coins[j])
				cur_min = min(cur_min, dp[i-coins[j]]+1);
		}
		dp[i] = cur_min;
	}
	cout<<dp[money];
}

int main(){
	int money, coins[3]={1,3,4}, cur_min;
	cin>>money;
	int dp[10000]={0};
	for(int i=1; i<=money; i++){
		cur_min = MAX;
		for(int j=0; j<3; j++){
			if(i>=coins[j])
				cur_min = min(cur_min, dp[i-coins[j]]+1);
		}
		dp[i] = cur_min;
	}
	cout<<dp[money];
}



#include <iostream>
#include <algorithm>
using namespace std;

void print_steps(int cur, int prev_step[]){
	if(cur==1){
		cout<<1;
		return;
	}
	print_steps(prev_step[cur], prev_step);
	cout<<' '<<cur;
}


int main(){
	int goal;
	cin>>goal;
	int dp[1000005]={0, 0};
	int prev_step[1000005]={0, 0};
	for(int i=2; i<=goal; i++){
		dp[i]=dp[i-1]+1;
		prev_step[i]=i-1;
		if(i%2==0 && dp[i]>dp[i/2]+1){
			dp[i] = dp[i/2]+1;
			prev_step[i] = i/2;
		}
		if(i%3==0 && dp[i]>dp[i/3]+1){
			dp[i] = dp[i/3] + 1;
			prev_step[i]=i/3;
		}
	}
	cout<<dp[goal]<<endl;
	print_steps(goal, prev_steps);
}


void print_steps(int cur, int prev_step[]){
	if(cur==1){
		cout<<1;
		return;
	}
	print_steps(prev_step[cur], prev_steps);
	cout<<' '<<cur;
}


void print_steps(int cur, int prev_step[]){
	if(cur==1){
		cout<<1;
		return;
	}
	print_steps(prev_step[cur], prev_step);
	cout<<' '<<cur;
}

int main(){
	int goal;
	cin>>goal;
	int dp[1000005]={0, 0};
	int prev_step[1000005]={0, 0};
	for(int i=2; i<=goal; i++){
		dp[i] = dp[i-1] + 1;
		prev_step[i] = i-1;
		if(i%2==0 && dp[i]>dp[i/2]+1){
			dp[i] = dp[i/2]+1;
			prev_step[i] = i/2;
		}
		if(i%3==0 && dp[i]>dp[i/3]+1){
			dp[i] = dp[i/3]+1;
			prev_step[i] = i/3;
		}
	}
	cout<<dp[goal]<<endl;
	print_steps(goal, prev_step);
}

int main(){
	int m, n, cur_max;
	int dp[105][105]={0}, A[105]={0}, B[105]={0};
	cin>>m;
	for(int i=1; i<=m; i++){
		cin>>A[i];
	}
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>B[i];
	}
	for(int i=1; i<=max(m, n); i++){
		dp[i][0]=0;
		dp[0][i]=0;
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<n; j++){
			cur_max = max(dp[i-1][j], dp[i][j-1]);
			if(A[i]==B[j])
				cur_max = max(cur_max, dp[i-1][j-1]);
			dp[i][j] = cur_max;
		}
	}
	cout<<dp[m][n];
}


int main(){
	int m, n, cur_max;
	int dp[105][105] = {0}, A[105]={0}, B[105]={0};
	cin>>m;
	for(int i=1; i<=m; i++){
		cin>>A[i];
	}
	for(int j=1; j<=n; j++){
		cin>>B[j];
	}
	for(int i=1; i<=max(m,n); i++){
		dp[i][0]=0;
		dp[0][i]=0;
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			cur_max = max(dp[i-1][j], dp[i][j-1]);
			if(A[i]==B[j])
				cur_max=max(cur_max, dp[i-1][j-1]+1);
			dp[i][j]=cur_max;
		}
	}
	cout<<dp[m][n];
}



int main(){
	int n, m, l, cur_max;
	int dp[105][105][105];
	int A[105], B[105], C[105];
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>A[i];
	}
	cin>>m;
	for(int i=1; i<=m; i++){
		cin>>B[i];
	}
	cin>>l;
	for(int i=1; i<=l; i++){
		cin>>C[i];
	}
	memset(dp, 0, sizeof(dp));
	for(int ni=1; ni<=n; ni++){
		for(int mi=1; mi<=m; mi++){
			for(int li=1; li<=l; li++){
				cur_max=max(dp[ni-1][mi][li], dp[ni][mi-1][li]);
				cur_max=max(cur_max, dp[ni][mi][li-1]);
				if(A[ni]==B[mi] && A[ni]==C[li])
					cur_max = max(cur_max, dp[ni-1][mi-1][li-1]+1);
				dp[ni][mi][li] = cur_max;
			}
		}
	}
	cout<<dp[n][m][l];
}


int main(){
	int n,m,l, cur_max;
	int dp[105][105][105];
	int A[105], B[105], C[105];
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>A[i];
	}
	cin>>m;
	for(int i=1; i<=m; i++){
		cin>>B[i];
	}
	cin>>l;
	for(int i=1; i<=l; i++){
		cin>>C[i];
	}
	memset(dp, 0, sizeof(dp));
	for(int ni=1; ni<=n; ni++){
		for(int mi=1; mi<=m; mi++){
			for(int li=1; li<=l; li++){
				cur_max = max(dp[ni-1][mi][li], dp[ni][mi-1][li]);
				cur_max = max(cur_max, dp[ni][mi][li-1]);
				if(A[ni]==B[mi] && A[ni]==C[li])
					cur_max = max(cur_max, dp[ni-1][mi-1][li-1]+1);
				dp[ni][mi][li] = cur_max;
			}
		}
	}
	cout<<dp[n][m][l];
}


int main(){
	string first, second;
	int cur_min;
	cin>>first>>second;
	int dp[105][105]={0};
	int len_a = first.length(), len_b = second.length();
	for(int i=1; i<=max(len_a, len_b); i++){
		dp[i][0]=i;
		dp[0][i]=i;
	}
	for(int i=1; i<=len_a; i++){
		for(int j=1; j<=len_b; j++){
			cur_min = min(dp[i-1][j]+1, dp[i][j-1]+1);
			if(first[i-1]==second[j-1])
				cur_min = min(cur_min, dp[i-1][j-1]);
			else
				cur_min = min(cur_min, dp[i-1][j-1]+1;)
			dp[i][j]=cur_min;
		}
	}
	cout<<dp[len_a][len_b];
}

int main(){
	string first, second;
	int cur_min;
	cin>>first>>second;
	int dp[105][105]={0};
	int len_a = first.length(), len_b=second.length();
	for(int i=1; i<=max(len_a, len_b); i++){
		dp[i][0]=i;
		dp[0][i]=i;
	}
	for(int i=1; i<=len_a; i++){
		for(int j=1; j<=len_b; j++){
			cur_min = min(dp[i-1][j]+1, dp[i][j-1]+1);
			if(first[i-1]==second[j-1])
				cur_min = min(cur_min, dp[i-1][j-1]);
			else
				cur_min = min(cur_min, dp[i-1][j-1]+1);
			dp[i][j]=cur_min;
		}
	}
	cout<<dp[len_a][len_b];
}


int main(){
	int W, n;
	cin>>W>>n;
	int gold[400]={0};
	for(int i=1; i<=n; i++){
		cin>>gold[i];
	}
	int dp[2][10090];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++){
		for(int w=1; w<=W; w++){
			dp[i%2][w]=dp[(i-1)%2][w];
			if(w>=gold[i])
				dp[i%2][w]=max(dp[i%2][w], dp[(i-1)%2][w-gold[i]]+gold[i]);
		}
	}
	cout<<dp[n%2][W];
}

int main(){
	int W, n;
	cin>>W>>n;
	int gold[400]={0};
	for(int i=1; i<=n; i++){
		cin>>gold[i];
	}
	int dp[2][10090];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++){
		for(int w=1; w<=W; w++){
			dp[i%2][w]=dp[(i-1)%2][w];
			if(w>=gold[i])
				dp[i%2][w]=max(dp[i%2][w], dp[(i-1)%2][w-gold[i]]+gold[i]);
		}
	}
	cout<<dp[n%2][W];
}


//with repetitions, recursive:
int knapsack(w){
	if(dp[w]!=-1)
		return dp[w];
	cur_max = 0;
	for(int i=1; i<=n; i++){
		if(weight[i]<=w)
			cur_max = max(cur_max, knapsack(w-weight[i])+value[i]);
	}
	dp[w]=cur_max;
	return dp[w];
}


int main(){
	int n, values[30], dp[2][601][601], weight=0;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>values[i];
		weight+=values[i];
	}
	if(weight%3!=0){
		cout<<0;
		return 0;
	}
	else{
		weight/=3;
	}
	memset(dp, 0, sizeof(dp));
	dp[1][0][0]=1;
	dp[1][values[1]][0]=1;
	dp[1][0][values[1]]=1;
	for(int i=2; i<=n; i++){
		for(int j=1; j<=weight; j++){
			for(int k=1; k<=weight; k++){
				dp[i%2][j][k]=dp[(i-1)%2][j][k];
				if(j>=values[i])
					dp[i%2][j][k]+=dp[(i-1)%2][j-values[i]][k];
				if(k>=values[i])
					dp[i%2][j][k]+=dp[(i-1)%2][j][k-values[i]];
			}
		}
	}
	if(dp[n%2][weight][weight]>0)
		cout<<1;
	else
		cout<<0;
}


int main(){
	int n, values[30], dp[2][601][601], weight=0;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>values[i];
		weight += values[i];
	}
	if(weight%3!=0){
		cout<<0;
		return 0;
	}
	else{
		weight/=3;
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0][0]=1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=weight; j++){
			for(int k=1; k<=weight; k++){
				dp[i%2][j][k]=dp[(i-1)%2][j][k];
				if(j>=values[i])
					dp[i%2][j][k]+=dp[(i-1)%2][j-values[i]][k];
				if(k>=values[i])
					dp[i%2][j][k]+=dp[(i-1)%2][j][k-values[i]];
			}
		}
	}
	if(dp[n%2][weight][weight]>0)
		cout<<1;
	else
		cout<<0;
}


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const long long INF=9999999;
char ops[20];
long long nums[30], n=1, m=1, small[30][30]={0};
long long calc(long long a, long long b, char op){
	if(op=='+')
		return a+b;
	if(op=='-')
		return a-b;
	return a*b;
}

void MinAndMax(int i, int j, long long &MIN, long long &MAX){
	MIN = INF;
	MAX = -INF;
	for(int k=i; k<=j-1; k++){
		long long a = calc(big[i][k], big[k+1][j], ops[k]);
		long long b = calc(big[i][k], small[k+1][j], ops[k]);
		long long c = calc(small[i][k], big[k+1][j], ops[k]);
		long long d = calc(small[i][k], small[k+1][j], ops[k]);
		MIN = min(MIN, min(min(a,b), min(c,d)));
		MAX = max(MAX, max(max(a,b), max(c,d)));
	}
}

void printMat(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<big[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<small[i][j]<<' ';
		}
		cout<<endl;
	}
}


int main(){
	string exp;
	cin>>exp;
	memset(big, 0, sizeof(big));
	memset(small, 0, sizeof(small));
	for(int i=0; i<exp.length(); i++){
		if(i%2==0){
			nums[n]=(exp[i]-'0');
			n++;
		}
		else{
			ops[m]=exp[i];
			m++;
		}
	}
	n--;
	for(int i=1; i<=n; i++){
		small[i][i]=nums[i][i];
		big[i][i]=nums[i][i];
	}
	int j;
	for(int s=1; s<=n-1; s++){
		for(int i=1; i<=n-s; i++){
			j=i+s;
			MinAndMax(i, j, small[i][j], big[i][j]);
		}
	}
	cout<<big[1][n];
}


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF=9999999;
char ops[20];
ll nums[30], n=1, m=1, small[30][30]={0}, big[30][30]={0};
ll calc(ll a, ll b, char ops){
	if(ops=='+')
		return a+b;
	if(ops=='-')
		return a-b;
	return a*b;
}

void MinAndMax(int i, int j, ll &MIN, ll &MAX){
	MIN = INF;
	MAX = -INF;
	for(int k=i; k<=j-1; k++){
		ll a = calc(big[i][k], big[k+1][j], ops[k]);
		ll b = calc(big[i][k], small[k+1][j], ops[k]);
		ll c = calc(small[i][k], big[k+1][j]);
		ll d = calc(small[i][k], small[k+1][j]);
		MIN = min(MIN, min(min(a,b), min(c,d)));
		MAX = max(MAX, max(max(a,b), max(c,d)));
	}
}

void MinAndMax(int i, int j, ll &MIN, ll&MAX){
	MIN = INF;
	MAX = -INF;
	for(int k=i; k<=j-1; k++){
		ll a = calc(big[i][k], big[k+1][j]);
		ll b = calc(big[i][k], small[k+1][j]);
		ll c = calc(small[i][k], big[k+1][j]);
		ll d = calc(small[i][k], small[k+1][j]);
		MIN = min(MIN, min(min(a,b), min(c,d)));
		MAX = max(MAX, max(max(a,b), max(c,d)));
	}
}

int main(){
	string exp;
	cin>>exp;
	memset(big, 0, sizeof(big));
	memset(small, 0, sizeof(small));
	for(int i=0; i<exp.length(); i++){
		if(i%2==0){
			nums[n]=(exp[i]-'0');
			n++;
		}
		else{
			ops[m]=exp[i];
			m++;
		}
	}
	n--;
	for(int i=1; i<=n; i++){
		small[i][i] = nums[i];
		big[i][i] = nums[i];
	}
	int j;
	for(int s=1; s<=n-1; s++){
		for(int i=1; i<=n-s; i++){
			j=i+s;
			MinAndMax(i, j, small[i][j], big[i][j]);
		}
	}
	cout<<big[1][n];
}










