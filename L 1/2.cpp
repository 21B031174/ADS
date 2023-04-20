#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec;
    int a;cin>>a;
    for(int i=0;i<a;i++){
        int b;cin>>b;
        vec.push_back(b);
    }
    cout<<"-1 ";
    for(int i=1;i<a;i++){
        bool ok = false;
        for(int j=i-1;j>=0;j--){
            if(vec[j]<=vec[i]){
                ok = true;
                cout<<vec[j] <<" ";
                break;
            }        
        }
        if(ok == false){
            cout<<"-1 ";
        }    
    }
}