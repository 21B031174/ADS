#include <iostream>
#include <vector>
using namespace std;
const long long q = 1e9+7, p=17;

long long toHash(string s){
    long long h = 0;
    long long power=1;
    for(int i=0; i<s.length(); i++){
        h = (h + ((s[i]-'a' + 1)*power)%q)%q;
        power = power*p%q;
    }
    return h;
}
vector<long long> getH(string s){
    long long power = 1;
    vector<long long> h(s.size());
    for(int i=0; i<s.size(); i++){
        h[i] = (s[i] - 'a' + 1)*power%q;
        if(i!=0) h[i] = (h[i-1]+h[i])%q;
        power=power*p%q;
    }
    return h;
}

int chek(string pattern, string str){
    int n=pattern.size(), k=str.size();
    int cnt=0, j = 0;
    long long h=toHash(pattern);
    vector<long long> codeH = getH(str);
    for(int i=0; i<k-n+1;i++){
        long long hashd = codeH[i+n-1];
        if(i!=0){
            hashd -=codeH[i-1];
            h=h*p%q;
        }
        if(hashd<0) hashd+=q;
        if(h==hashd){
            for(j =0; j<n; j++){
                if(str[i+j] != pattern[j]){
                    break;
                }
            }
            if(j==n) cnt++;
        } 
    }
    return cnt;
}
int main(){
    string str; cin >> str;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int l, r; cin >> l >> r;
        cout << chek(str.substr(l-1, r-(l-1)), str) << endl;
    }
    return 0;
}