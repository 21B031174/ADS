#include <iostream>
#include <vector>

using namespace std;

int f2(string str,int k){
    int n = str.size();
    // cout<<str.substr(0, 2) <<" "<< str.substr(n-2,n-1)<<endl;
    for(int i=1;i<k;i++){
        if(str.substr(0, i)  == str.substr(n-i,n-1)){
            if(str.substr(i, k-i)  == str.substr(k+1, k-i)){
                return k-i;
            }
        }
    }
    return -1;
}


int main(){

    string s1;
    string s2;
    cin>>s1>>s2;
    int k = s1.size();
    string str = s1 + '#'  + s2;

    int v = f2(str,k);
    cout<<v;
    return 0;
}
