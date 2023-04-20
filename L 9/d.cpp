#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long f(string str,long long l){
    long long n = str.size();
    for(long long i=l;i>=1;i--){
        if(str.substr(0, i)  == str.substr(n-i, i)){
            return i;
        }
        // cout<<str.substr(0, i)<<" "<<str.substr(n-i, i)<<endl;
    }
    return -1;
}

int main(){
    string s1,s2;
    long long a,k;
    cin>>s1>>a;
    s1[0]=tolower(s1[0]);
    vector<string> v1;
    long long cnt=0,max=0;

    for(long long i=0;i<a;i++){
        cin>>s2;
        s2[0]=tolower(s2[0]);
        string str = s2+"#"+s1;
        k=f(str,s1.size());
        
        if(k>max){
            max = k;
            v1.clear();
            cnt=1;
            s2[0]=toupper(s2[0]);
            v1.push_back(s2);
        }
        else if(k==max){
            s2[0]=toupper(s2[0]);
            v1.push_back(s2);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(long long i = 0; i < v1.size(); ++i){
        cout<<v1[i]<<endl;    
    }
    return 0;
}

// ////////////
// /////
