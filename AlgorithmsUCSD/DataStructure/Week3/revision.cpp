#include <iostream>
#include <unordered_map>
#include <cstring>
#include <utility>
using namespace std;

int main(){
	unordered_map<int, string> book;

	int N, num;
	string op, name;
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>op;
		if(op=='add'){
			cin>>num>>name;
			unordered_map<int, string>::iterator iter;
			iter = book.find(num);
			if(iter == book.end()){
				book.insert(make_paie(num, name));
			}
			else{
				iter->second = name;
			}
		}
		else if(op=='find'){
			cin>>num;
			unordered_map<int, string>::iterator iter;
			iter = book.find(num);
			if(iter == book.end()){
				cout<<"not found"<<endl;
			}
			else{
				cout<<iter->second<<endl;
			}
		}
		else if(op=='del'){
			cin>>num;
			book.erase(num);
		}
	}
}

#include <iostream>
#include <unordered_map>
#include <cstring>
#include <utility>
using namespace std;

int main(){
	unordered_map<int, string> book;

	int N, num;
	string op, name;
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>op;
		if(op=='add'){
			cin>>num>>name;
			unordered_map<int, string>::iterator iter;
			iter = book.find(num);
			if(iter==book.end()){
				book.insert(make_pair(num, name));
			}
			else{
				iter->second = name;
			}
		}
		else if(op=='find'){
			cin>>num;
			unordered_map<int, string>::iterator iter;
			iter = book.find(num);
			if(iter==book.end()){
				cout<<'not found'<<endl;
			}
			else{
				cout<<iter->second<<endl;
			}
		}
		else if(op=='del'){
			cin>>num;
			book.erase(num);
		}
	}
}


#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>
using namespace std;

typedef long long ll;
int m, x=263;
const ll p=1000000007;

ll PolyHash(string S){
	ll hash = 0;
	for(int i=S.length()-1; i>=0; i--){
		hash = (hash*x%p + int(S[i])%p)%p;
	}
	hash = hash%m;
	return hash;
}

int main(){
	int N;
	string key, op;
	cin>>m>>N;
	vector<unordered_set<string> > hashTable(m);
	for(int i=0; i<N; i++){
		cin>>op;
		if(op=='add'){
			cin>>key;
			ll hashK = PolyHash(key);
			hashTable[hashK].insert(key);
		}
		else if(op=='del'){
			cin>>key;
			ll hashK = PolyHash(key);
			unordered_set<string>::iterator iter;
			iter = hashTable[hashK].find(key);
			if(iter != hashTable[hashK].end())
				hashTable[hashK].erase(iter);
		}
		else if(op=='find'){
			cin>>key;
			ll hashK = PolyHash(key);
			unordered_set<string>::iterator iter;
			iter = hashTable[hashK].find(key);
			if(hashTable[hashK].empty() || iter==hashTable[hashK].end())
				cout<<'no'<<endl;
			else
				cout<<'yes'<<endl;
		}
		else if(op=='check'){
			int t;
			cin>>t;
			unordered_set<string>::iterator iter;
			if(!hashTable[t].empty()){
				for(iter=hashTable[t].begin(); iter!=hashTable[t].end(); iter++)
					cout<<(*iter)<<endl;
				cout<<endl;
			}
		}
	}
}




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





























