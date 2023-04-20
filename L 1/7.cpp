#include <iostream>

using namespace std;

int IsPrime(int n){
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
            return i;
            break;
        }
        i+=2;
    }
    
}


int main(){
    int a;cin>>a;
    if(a==1)cout<<3;
    else{
        cout<<IsPrime(IsPrime(a));
    }
    
}