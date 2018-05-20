#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const long long INF=9999999;
char ops[20];
long long nums[30], n=1, m=1, small[30][30]={0}, big[30][30]={0};
long long calc(long long a, long long b, char op){
    if(op=='+')
        return a+b;
    if(op=='-')
        return a-b;
    return a*b;
}

void MinAndMax(int i, int j, long long &MIN, long long &MAX){
    MIN=INF;
    MAX=-INF;
    for(int k=i; k<=j-1; k++){
        long long a = calc(big[i][k], big[k+1][j], ops[k]);
        long long b = calc(big[i][k], small[k+1][j], ops[k]);
        long long c = calc(small[i][k], big[k+1][j], ops[k]);
        long long d = calc(small[i][k], small[k+1][j], ops[k]);
        //get min and max over all possibilities
        MIN=min(MIN, min(min(a,b), min(c,d)));
        MAX=max(MAX, max(max(a,b), max(c,d)));
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
        small[i][i]=nums[i];
        big[i][i]=nums[i];
    }
    int j;
    for(int s=1; s<=n-1; s++){
        for(int i=1; i<=n-s; i++){
            j=i+s;
            MinAndMax(i, j, small[i][j], big[i][j]);
        }
        //printMat();
    }
    cout<<big[1][n];
}





