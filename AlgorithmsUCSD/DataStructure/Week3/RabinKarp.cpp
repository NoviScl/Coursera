#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
int p=1000000007, x=263;
string pattern, text;

ll PolyHash(string S){
    ll hash = 0;
    for(int i=S.length()-1; i>=0; i--){
        hash = (hash*x%p + int(S[i]))%p;
    }
    return hash;
}

vector<ll> hashVal(600000);
vector<ll> result;

void preCompute(){
    int P = pattern.length();
    int T = text.length();
    hashVal[T-P] = PolyHash(text.substr(T-P));
    ll y=1;
    for(int i=1; i<=P; i++){
        y = (y*x)%p;
    }
    for(int i=(T-P-1); i>=0; i--){
        hashVal[i] = ((x*hashVal[i+1]+int(text[i])-y*int(text[i+P]))%p+p)%p;
    }
}

bool AreEqual(string a, string b){
    if(a.length()!=b.length())
        return false;
    for(int i=0; i<a.length(); i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

void RabinKarp(){
    int T=text.length(), P=pattern.length();
    preCompute();
    ll hashK = PolyHash(pattern);
    for(int i=0; i<=T-P; i++){
        if(hashVal[i]!=hashK)
            continue;
        else if(AreEqual(pattern, text.substr(i, P)))
            result.push_back(i);
    }
}


//optimization:
//text.substr() creates a new string and uses extra memory
//can pass in the entire array and pos index to calculate hash instead
int main(){
    cin>>pattern>>text;
    RabinKarp();
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<' ';
    }
    cout<<endl;
}








