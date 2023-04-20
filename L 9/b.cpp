#include <iostream>
#include <vector>

using namespace std;

vector<int> kmp(string str){
    long n = str.size();
    vector<int> v(n);
    v[0] = 0;
    for(int i = 1; i < n; ++i){
        int j = v[i - 1];
        while(j > 0 && str[j] != str[i]){
            j = v[j-1];
        }
        if(str[i] == str[j]){
            v[i] = j + 1;
        }
    }
    return v;
}

int main(){

    string s1;
    string s2;
    long a,cnt=0;
    cin>>s1>>a;
    cin>>s2;
    string str =s1+'@'+s2;
    vector<int> v = kmp(str);
    for(int i = 0;i < v.size();i++){
        if(v[i] == s1.size()){
            cnt++;
        }
    }
    if(cnt>=a){
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}