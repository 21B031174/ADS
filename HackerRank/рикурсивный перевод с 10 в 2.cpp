#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a;
    cin>>a;
    string n;
    while(a!=0){
      n+=char(a%2+48);
      a/=2;
    }
    // reverse(n.begin(),n.end());
    cout<<n;
    
}
// int f(int a){
//     if(a==0){return 0;}
//     f(a/2);
//     cout<<a%2;
// }


// int main(){
//     int a;
//     cin>>a;
//     f(a);
//     return 0;

// }