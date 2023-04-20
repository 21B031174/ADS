#include <iostream>
#include <vector>
using namespace std;
int p=17, q=1e9+7;
long long toHash(string s){
    long long power=1;
    int h=0;
    for(int i=0; i<s.length(); i++){
        h = (h + (s[i] - 'a' + 1)*power) %q;
        power = (power*p)%q; 
    }
    return h;
}
vector<long long> getH(string s){
    vector<long long> h(s.size());
    long long power=1;
    for(int i=0; i<s.size(); i++){
        h[i] = (s[i] -'a' +1)*power;
        if(i!=0) h[i] = (h[i-1] + h[i]) %q;
        power = (power*p)%q;
    }
    return h;
}
int search(string pattern, string str){
    long long h = toHash(pattern);
    int cnt=0;
    vector<long long> codeH = getH(str);
    for(int i=0; i<= str.size()-pattern.size()+1; i++){
        long long hashd = codeH[i+pattern.size()-1];
        if(i!=0) hashd -= codeH[i-1];
        if(i!=0) h=h*p%q;
        if(hashd<0) hashd += q;
        if(h == hashd)cnt++;
    }
    return cnt;
}


int main(){
    while(true){
        int n; cin>>n;
        if(n==0)break;
        vector<string> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        string s; cin >>s;
        vector<pair<string, int> > vec;
        for(int i=0; i<n; i++){
            vec.push_back(make_pair(v[i], search(v[i], s)));
        }
        int u = -1e9;
        for(int i=0; i<n; i++){
            if(vec[i].second > u) u = vec[i].second;
        }
        cout<<u<<endl;
        for(int i=0; i<n; i++){
            if(vec[i].second == u) cout << vec[i].first << endl;
        }

    }


}