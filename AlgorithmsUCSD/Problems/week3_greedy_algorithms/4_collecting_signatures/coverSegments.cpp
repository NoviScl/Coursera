#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Segment {
  int start, end;
};

bool cmp(Segment a, Segment b){
  return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int cur_point = segments[0].end;
  points.push_back(cur_point);
  for(size_t i=1; i<segments.size(); i++){
    if(segments[i].start>cur_point){
      cur_point = segments[i].end;
      points.push_back(cur_point);
    }
  }
  return points;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < n; ++i) {
    cin >> segments[i].start >> segments[i].end;
  }
  sort(segments.begin(), segments.end(), cmp);
  vector<int> points = optimal_points(segments);
  cout << points.size() << endl;
  for (size_t i = 0; i < points.size(); ++i) {
    cout << points[i] << " ";
  }
}
