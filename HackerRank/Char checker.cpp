#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int all;
    string ch;
    cin>>all;
    set<char> s;
    vector<char> v;
    for (int i = 0; i < all; i++)
    {
        cin>>ch;
        for (int i = 0; i < ch.size(); i++)
        {
            s.insert(ch[i]);
        }
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        v.push_back(i);
    }
    set<char>::iterator it;
    for (int i = 0; i < v.size(); i++)
    {
        for(it=s.begin();it!=s.end();it++){
            if(v[i]==*it){
                v.erase(v.begin()+i);
                i--;
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i];
    }
    if(v.size()==0)cout<<"No such characters";
}