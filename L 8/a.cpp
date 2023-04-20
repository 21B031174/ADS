#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;



long long toHash(string s){
    long long q=1e9+7;
    long long k = 0;
    long long p[s.size()];
    p[0] = 1;
    for(long long i=1;i<s.size();i++){
        p[i] = (p[i-1]*11)%q;
    }
    for(long long i = 0;i<s.size();i++){
        k = (k+((int(s[i])-47)*p[i])%q)%q;
    }   
    return k;
}



int main(){ 
    int n;cin>>n;
    int l=n*2;
    map<string,int> m;
    string arr[l][2];
    for(int i=0;i<n*2;i++){
        string s;cin>>s;
        m[s]=1;
        arr[i][0]=s;
        arr[i][1]=to_string(toHash(s));
    }
    int cnt=0;
    for(int i=0;i<l;i++){
        if(m.find(arr[i][1])!=m.end()){
            cout<<"Hash of string \""<<arr[i][0]<<'"'<<" is "<<arr[i][1]<<endl;
            cnt++;
        }
        if(cnt==n){
            break;
        }
    }
    
    
}