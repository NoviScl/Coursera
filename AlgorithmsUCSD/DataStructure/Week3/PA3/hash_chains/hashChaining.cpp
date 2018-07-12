#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor{
	int bucket_count;
	vector<deque<string> > data_;
	size_t hash_func(const string& s) const {
		static const size_t multiplier = 263;
		static const size_t prime = 1000000007;
		unsigned long long hash = 0;
		for(int i=static_cast<int> (s.size()) -1; i>=0; i--)
			hash = (hash*multiplier + s[i])%prime;
		return hash%bucket_count;
	}

public:
	explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}
	Query readQuery() const{
		Query query;
		cin>>query.type;
		if(query.type != "check")
			cin>>query.s;
		else
			cin>>query.ind;
		return query;
	}

	void writeSearchResult(bool was_found) const {
		cout<<(was_found ? "yes\n" : "no\n");
	}

	void insert(const string &str){
		int bc = hash_func(str);
		auto &q = data_[bc];
		if(find(q.begin(), q.end(), str) == q.end())
			q.push_back(str);
	}

	void check(int ind){
		const auto &q = data_[ind];
		if(!q.empty()){
			for(auto it = q.begn(); it!=q.end(); it++)
				cout<<*it<<' ';
			cout<<endl;
		}		
	}

	bool find(const string &str){
		int bc = hash_func(str);
		const auto &q = data_[bc];
		auto it = find(q.begin(), q.end(), str);
		return it!=q.end();
	}

	void del(const string &str){
		int bc = hash_func(str);
		auto &q = data_[bc];
		auto it = find(q.begin(), q.end(), str);
		if(it!= q.end())
			q.erase(it);
	}

	void processQuery(const Query &query){
		if(query.type=="check"){
			check(query.ind);
		}
		else if(query.type=="find"){
			writeSearchResult(find(query.s));
		}
		else if(query.typr=="add"){
			insert(query.s);
		}
		else if(query.type=="del"){
			del(query.s);
		}
	}

	void processQueries(){
		int n;
		cin>>n;
		for(int i=0; i<n; i++){
			processQuery(readQuery());
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int bucket_count;
	cin>>bucket_count;
	QueryProcessor proc(bucket_count);
	proc.processQueries();
	return 0;
}

















