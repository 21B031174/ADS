#include <iostream>
using namespace std;
int main(){
    int a;cin>>a;
    bool ok = true;
    if(a==1){
        cout<<"NO";
        return 0;
    }
    for(int i=2;i<=a/2;i++){
        if(a%i==0){
            cout<<"NO";
            ok = false;
            return 0;
        }

    }
    cout<<"YES";
}