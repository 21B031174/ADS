#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int a;
    cin>>a;
    vector<char> v;
    set<int> s;
    for (int i = 0; i < a; i++)
    {
        int x;cin>>x;
        v.push_back(x);
        s.insert(x);
    }
    if(v.size()==s.size())cout<<"YES";
    else cout<<"NO";    

}