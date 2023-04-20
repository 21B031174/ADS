#include <iostream>

#include <string>

using namespace std;

// int f(int a,int b,int c=0){
//     if(a==0)return b;
//     return f(a/10,b+((a%10)*pow(2,c)),c+1);
// }

// int main(){
//     int a,b=0;
//     string s;
//     cin>>s;
//     int size=s.size();
//     for (int i = 0; i < s.size(); i++)
//     {
//         a+=(s[i]-'0')*pow(10,size-1);
//         size--;
//     }
    
//     cout<<f(a,b);
// }

int main(){
    string s;
    cin>>s;
    int i_dec = std::stoi (s);
    cout<<i_dec;
}