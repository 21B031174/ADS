#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

long long q=9007199254740881,d=587;

long long toHash(unordered_map<long long, int> &m,long long k,string s){
    long long n=s.size();
    long long cnt=0,t=0;
    for (int i=k;i<n; i++){
        t = (int(s[i])+d*t)%q;
        if (m.find(t)==m.end()){
            m[t]=1;
            cnt++;
        }
    }
    return cnt;
}

int main(){
    unordered_map<long long,int> m;
    string s;
    cin >> s;
    long long cnt=0;
    for (long long i=0;i<s.size();i++){
        cnt += toHash(m,i,s);
    }
    cout << cnt;
    return 0;
}