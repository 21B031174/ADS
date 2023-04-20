#include <iostream>

using namespace std;

int main(){
    int a;cin>>a;
    int cnt=0;
    if(a==0 || a==1){
        cout<<0;
        return 0;;
    }
    int j=2;
    int k = j;
    bool ok =false;
    while(a>1){
        if(a%j==0){
            if(!ok){
                ok=true;
                k = j;
                cnt++;
            }
            else if(k!=j && ok){
                cnt++;
                k=j;
            }
            a/=j;
        }
        else j++;
    }
    cout<<cnt;
}