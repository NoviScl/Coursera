#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
int m, x=263;
const ll p=1000000007;

ll PolyHash(string S){
    ll hash = 0;
    for(int i=S.length()-1; i>=0; i--){
        hash = (hash*x%p + int(S[i]))%p;
    }
    hash = hash%m;
    return hash;
}

int find(vector<string> &L, string K){
    for(int i=0; i<L.size(); i++){
        if(L[i]==K)
            return i;
    }
    return -1;
}

int main(){
    int N;
    string key, op;
    cin>>m>>N;
    vector<vector<string> > hashTable(m);
    for(int i=0; i<N; i++){
        cin>>op;
        if(op=="add"){
            cin>>key;
            ll hashK = PolyHash(key);
            if(hashTable[hashK].empty() || find(hashTable[hashK], key)==-1){
                hashTable[hashK].push_back(key);
            }
        }
        else if(op=="del"){
            cin>>key;
            ll hashK = PolyHash(key);
            int pos = find(hashTable[hashK], key);
            if(pos>-1){
                hashTable[hashK].erase(hashTable[hashK].begin()+pos);
            }
        }
        else if(op=="find"){
            cin>>key;
            ll hashK = PolyHash(key);
            if(find(hashTable[hashK], key)>-1)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
        else if(op=="check"){
            int t;
            cin>>t;
            if(hashTable[t].size()>0){
                for(int i=hashTable[t].size()-1; i>=0; i--){
                    cout<<hashTable[t][i]<<' ';
                }
            }
            cout<<endl;
        }
    }
}