#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=99999;
struct point{
    int pos;
    int types; //1: close, 2: query, 3: open
    int index=MAX;
    int cover=-1;
};

//sweep line algorithm
//if meet an open, count+1; meet a close, count-1; meet a query, output count
void fast_count_segments(vector<point> &data) {
    int count=0;
    for(int i=0; i<data.size(); i++){
        if(data[i].types==2) //query
            data[i].cover=count;
        else if(data[i].types==1)
            count--;
        else  //open
            count++;
    }
}

// vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
//   vector<int> cnt(points.size());
//   for (size_t i = 0; i < points.size(); i++) {
//     for (size_t j = 0; j < starts.size(); j++) {
//       cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
//     }
//   }
//   return cnt;
// }

bool cmp1(point a, point b){
    if(a.pos==b.pos)
        return a.types > b.types;
    return a.pos < b.pos;
}

bool cmp2(point a, point b){
    return a.index < b.index;
}

int main() {
    int n, m;
    point temp;
    cin >> n >> m;
    vector<point> data;
    for (size_t i = 0; i < n; i++) {
        cin>>temp.pos;
        temp.types=3;
        data.push_back(temp);
        cin>>temp.pos;
        temp.types=1;
        data.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
        cin>>temp.pos;
        temp.index=i;
        temp.types=2;
        data.push_back(temp);
    }
    sort(data.begin(), data.end(), cmp1);
    fast_count_segments(data);
    sort(data.begin(), data.end(), cmp2);
    //use fast_count_segments
    for (size_t i = 0; i < m; i++) {
        cout<<data[i].cover<<' ';
    }
}










