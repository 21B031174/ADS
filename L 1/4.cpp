#include <iostream>
#include <deque>
using namespace std;
int main(){
    string s;
    deque<char> dec;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(dec.empty()){
            dec.push_back(s[i]);
        }
        else{
            if(dec.back()==s[i]){
                dec.pop_back();
            }
            else{
                dec.push_back(s[i]);
            }
        }
    }
    if(dec.empty()){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
}