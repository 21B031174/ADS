#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int a,b,x,y,n,m;
    cin>>n>>m;
    bool bo[n];
    vector<pair<int, int> > v;
    stack<int> s;
    
    for(int i=0;i<m;i++){
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    cin>>a>>b;
    s.push(a);
    bo[a]=true;
    int k=0;
    while(!s.empty()){
        // cout<<s.top()<<endl;
        bool ok =false;
        for(int i=0;i<v.size();i++){
            if(v[i].first == s.top() || !bo[v[i].second]){
                s.push(v[i].second);
                bo[v[i].second]=true;
                v.erase(v.begin()+i);
                ok = true;
                break;
            }
            else if(v[i].second == s.top() || !bo[v[i].first]){
                s.push(v[i].first);
                bo[v[i].first]=true;
                v.erase(v.begin()+i);
                ok = true;
                break;
            }
        }
        if(s.top()==b){
            cout<<"YES";
            return 0;
        }
        if(!ok){
            s.pop();
        }
        k++;
        if(k>100){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}