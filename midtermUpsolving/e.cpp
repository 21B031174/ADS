#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int a,b;cin>>a;
    for(int i=0;i<a;i++){
        string s;cin>>s;
        if(s == "add"){
            cin>>b;
            v.push_back(b);
        }
        else if(s == "delete"){
            if(v.size()!=0)v.pop_back();
            else cout<<"error"<<endl;
        }
        else if(s == "getcur"){
            if(v.size()!=0)cout<<v[v.size()-1]<<endl;
            else cout<<"error"<<endl;
        }
        else{
            if(v.size()!=0){
                int max=0;
                for(int i=0;i<v.size();i++){
                    if(max<v[i])max=v[i];
                }
                cout<<max<<endl;
            }
            else cout<<"error"<<endl;
        }
    }
}