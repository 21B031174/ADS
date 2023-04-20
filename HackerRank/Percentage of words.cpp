#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int a;
    cin>>a;
    vector<char> v;
    map<string,int> m;
    string s;
    for (int i = 0; i < a; i++)
    {
        int x;cin>>s>>x;
        
        m[s]=x;
    }
    map<string,int>::iterator i;
    for(i=m.begin();i!=m.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }

}