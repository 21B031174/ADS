#include <iostream>
#include <vector>
using namespace std;

void IsPrime(int n){
    vector<int> vec;
    int cnt=1;
    int i=3;
    bool ok=true;
    while(true){
        ok=true;
        for(int j=2;j<i;j++){
            if(i%j==0)ok=false;
        }
        if(ok){
            cnt++;
        }
        if(cnt==n){
            cout<<i;
            break;
        }
        i+=2;
    }
}

int main(){
    int a;cin>>a;
    if(a==1)cout<<2;
    else{
        IsPrime(a);
    }
}