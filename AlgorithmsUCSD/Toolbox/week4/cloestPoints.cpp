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
    return sqrt(pow(a.x - b.x, 2)+pow(a.y - b.y, 2));
}

double brute_force(vector<point> P){
    int n=P.size();
    double MIN = MAX;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(dist(P[i], P[j])<MIN)
                MIN = dist(P[i], P[j]);
        }
    }
    return MIN;
}


//O(nlogn) for sorting
//optimization: remove the sorting here --> O(n)
//the inner loop runs at most 7 times, so the two loops are O(n)
double stripClosest(vector<point> Pstrip, double d){
    int n=Pstrip.size();
    double best=d;
    sort(Pstrip.begin(), Pstrip.end(), compareY);
    for(int i=0; i<n; i++){
        //only need to search for 7 next points at most
        for(int j=1; j<=min(7, n-1-i); j++){
            if(dist(Pstrip[i], Pstrip[i+j])<best)
                best = dist(Pstrip[i], Pstrip[i+j]);
        }
    }
    return best;
}
//optimized:
// double stripClosest(vector<point> Pstrip, double d){
//     int n=Pstrip.size();
//     double best=d;
//     for(int i=0; i<n; i++){
//         //only need to search for 7 next points at most
//         for(int j=1; j<=min(7, n-1-i); j++){
//             if(dist(Pstrip[i], Pstrip[i+j])<best)
//                 best = dist(Pstrip[i], Pstrip[i+j]);
//         }
//     }
//     return best;
// }

// //P is already sorted by x-coordinate
double cloestPair(vector<point> P){
    //if n<=3, after split do not have a pair on one side
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
        if(abs(P[i].x-midP.x)<best)
            Pstrip.push_back(P[i]);
    }
    return min(best, stripClosest(Pstrip, best));
}
//Px contains all points sorted by x-coordinate
//Py contains all points sorted by y-coordiante
//put both sort into the main function instead of the recursion
//Optimized: O(nlogn)
//normal method: O(n(logn)^2)
//Note that this optimized method only works if there are no repeated points,
//because it is very hard to seperate Py in O(n) if there are multiple repeated points (I tried but gave up in the end)
// double cloestPair(vector<point> Px, vector<point> Py){
//     //if n<=3, after split do not have a pair on one side
//     int n = Px.size();
//     if(n<=3)
//         return brute_force(Px);
//     int mid = n/2;
//     point midP = Px[mid];

//     vector<point> Pyl;
//     vector<point> Pyr;
//     //note that midP is in Right
//     //the split of Px and Py should be consistent
//     for(int i=0; i<n; i++){
//      if(Py[i].x < midP.x || (Py[i].x == midP.x && Py[i].y<midP.y))
//          Pyl.push_back(Py[i]);
//      else if(Py[i].x > midP.x)
//          Pyr.push_back(Py[i]);
//     }


//     vector<point> Left(Px.begin(), Px.begin()+mid);
//     vector<point> Right(Px.begin()+mid+1, Px.end());
//     double dl = cloestPair(Left, Pyl);
//     double dr = cloestPair(Right, Pyr);

//     double best = min(dl, dr);

//     vector<point> Pstrip;
//     for(int i=0; i<n; i++){
//         if(abs(Py[i].x-midP.x)<best)
//             Pstrip.push_back(Py[i]);
//     }

//     return min(best, stripClosest(Pstrip, best));
// }


int main(){
    int N;
    point temp;
    cin>>N;
    vector<point> Px;
    //vector<point> Py;
    for(int i=0; i<N; i++){
        cin>>temp.x>>temp.y;
        Px.push_back(temp);
        //Py.push_back(temp);
    }
    sort(Px.begin(), Px.end(), compareX);
    //sort(Py.begin(), Py.end(), compareY);
    cout<<fixed;
    cout<<setprecision(9)<<double(cloestPair(Px))<<endl;
}




