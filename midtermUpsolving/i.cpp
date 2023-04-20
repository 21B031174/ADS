#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;cin>>n;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        vector <long long> v;
        while (x!=0){
            if(x%2==0) v.push_back(0);
            else{
                if(v.empty() or v.back()==1) v.push_back(1);
                else v.pop_back();
            }
            x=x/2;
        }
        if(v.size()==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }



    return 0;
}