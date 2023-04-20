#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int all,x,sh;
    cin>>all;
    vector<int> v;
    for (int i = 0; i < all; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cin>>sh;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]<sh){
            v.erase(v.begin()+i);
            i--;
        }
    }
    cout<<v.size();
}
    
    