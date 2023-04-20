#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    int a,k=0,p=0,l=0,r=0,t=0;
    bool ok=true;
    cin>>a;
    string s;
    vector<char> v;
    for(int i=0;i<a+1;i++){
        getline(cin,s);
        for (int j = 0; j < s.size(); j++)
        {
            v.push_back(s[j]);
        }
        
    }
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]=='('){
            k++;
            p++;
        }
        else if(v[i]==')')k--;
        else if(v[i]=='{'){
            l++;
            p++;
        }
        else if(v[i]=='}')l--;
        else if(v[i]=='['){
            r++;
        }
        else if(v[i]==']')r--;
        if(k<0){
            ok=false;
            break;
        }
        if(l<0){
            ok=false;
            break;
        }
        if(r<0){
            ok=false;
            break;
        }
    }
    if(k!=0||l!=0||r!=0)ok=false;
    if(ok&&p>0)cout<<"YES";
    else cout<<"NO";
    
    return 0;
}

