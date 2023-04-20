#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    stack<int> s; 
    int n,a,b,k;
    cin>>n;
    vector<pair<int, int> > v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>k;
            if(k==1){
                bool o =true;
                for(int p=0;p<v.size();p++){
                    if((v[p].first == i && v[p].second == j)||(v[p].first == j && v[p].second == i)){
                        o = false;
                        break;
                    }
                }
                if(o){
                    v.push_back(make_pair(i,j));
                }
            }
        }
    }
    cin>>a>>b;
    a--;
    b--;
    for(int i=0;i<v.size();i++){
        if((v[i].first==a && v[i].second == b)||(v[i].first==b && v[i].second == a)){
            cout<<1;
            return 0;
        }
    }
    s.push(a);
    int u=0;
    while(s.top()!=b){
        bool ok =false;
        for(int i=0;i<v.size();i++){
            if(v[i].first == s.top()){
                
                s.push(v[i].second);
                ok = true;
                v.erase(v.begin()+i);
                break;
            }
            else if(v[i].second == s.top()){
                s.push(v[i].first);
                ok = true;
                v.erase(v.begin()+i);
                break;
            }
        }
        // cout<<s.size()<<endl;
        if(v.size()>4){
            ok = false;
        }
        if(!ok){
            s.pop();
        }
        u++;
        if(u>10){
            cout<<-1;
            return 0;
        }
    }
    cout<<s.size()-1;

}