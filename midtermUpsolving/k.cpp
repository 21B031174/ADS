#include <iostream>
#include <deque>
using namespace std;
int main(){
    int a,b,c;cin>>a;
    deque<int> v;
    bool ok =true;
    for(int i=0;i<a;i++){
        cin>>b;
        if(b==1){
            cin>>c;
            if(ok)v.push_back(c);
            else v.push_front(c);
        }
        else if(b==2){
            if(ok)ok=false;
            else ok = true;
        }
    }
    if(ok){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }
    else{
        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
    }
}