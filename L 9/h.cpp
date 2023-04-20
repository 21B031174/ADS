#include <iostream>
#include <vector>
using namespace std;
vector <int> f(string s){
    int n = s.size();
    vector <int> v(n);
    for(int i = 1; i < n; i++){
        int j = v[i-1];
        while(j > 0 && s[i] != s[j]){
            j = v[j-1]; 
        }
        if(s[i] == s[j])v[i] = j+1;
    }
    return v;
}
int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector <int> v = f(s);
    int cnt = 0;
    for(int i = 1; i < n-1; i+=2){
        int k = i+1-v[i];
        if( (i+1) % k == 0){
            if(((i+1)/2)%k == 0)cnt++;
        }
    }
    cout << cnt;
    return 0;
}