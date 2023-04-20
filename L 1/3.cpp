#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.size();i++){
        if(a[i] == '#'){
            a.erase(i-1,2);
            i-=2;
        }
    }
    for(int i=0;i<b.size();i++){
        if(b[i] == '#'){
            b.erase(i-1,2);
            i-=2;
        }
    }
    if(a==b){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}