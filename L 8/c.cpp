#include <iostream>
#include <vector>

using namespace std;
long long q = 9223372036854775807;
vector <long long > h_txt;
vector <long long > p;
int n;

void fi(vector <bool > & chek , string str){
    long long h_str=0;
    for(int i=0;i<str.size();i++){
        h_str = (h_str+(((str[i]-int('a')+1)*p[i])%q))%q;
    }
    for(int i=0;(i+str.size()-1)<n;i++){
        long long cur = h_txt[i+str.size()-1];
        if(i>0){
            cur -= h_txt[i-1];
        }
        if(cur == h_str*p[i]){
            for(int j = i ; j<i+str.size();j++){
                chek[j] = 1;
            }
            
        }
    }
}
int main(){
    string txt;cin>>txt;
    n = txt.size();
    vector <bool> chek(n);
    p.push_back(1);
    for(int i=1;i<n;i++){
        p.push_back((p[i-1]*13)%q);
    }
    for(int i=0;i<n;i++){
        h_txt.push_back((((txt[i]-int('a')+1)*p[i])%q));
        if(i>0){
            h_txt[i] = (h_txt[i]+h_txt[i-1])%q;
        }
    }
    int z;cin>>z;
    for(int i=0;i<z;i++){
        string str;cin>>str;
        fi(chek,str);
    }
    for(int i=0;i<n;i++){
        if(chek[i]==0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}