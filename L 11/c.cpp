#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int par[10000];

int chek(int i){
    if(i == par[i])return i;
    return par[i] = chek(par[i]);
}


int main(){
    int n, m, x, y, a, b, c;
    string s;
    cin>>n>>m;
    cin>>x>>y;

    vector<pair<int, pair<int, int> > > v;

    for(int i=0;i<m;i++){
        cin>>s>>a>>b>>c;
        if(s == "both")v.push_back(make_pair(c*min(x,y), make_pair(a, b)));
        else if(s == "small")v.push_back(make_pair(c*y, make_pair(a, b)));
        else if(s == "big")v.push_back(make_pair(c*x, make_pair(a, b)));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)par[i] = i;

    int sum = 0;
    for(int i=0;i<v.size();i++){
        int fir = v[i].second.first;
        int sec = v[i].second.second;
        int cost = v[i].first;
        
        if(chek(sec) != chek(fir)){
            sum += cost;
            int k = chek(sec);
            int u = chek(fir);
            par[k] = par[u];
        }
    }

    cout << sum;


}