#include <iostream>
#include <vector>

using namespace std;

void f(string s2, vector<int>& v){
    v[0] = 0;                   
    int j = 0,i=1;
    while (i<s2.size()){
        if(s2[i]==s2[j]){   
            j++;
            v[i++] = j;
        }
        else{                   
            if(j==0) v[i++] = 0;
            else j = v[j-1];
        }
    }
}
int kmp(string s2,string s1){
    int n = s1.size();
    int m = s2.size();
    int i=0,j=0;
    vector<int> v(m);
    f(s2,v); 
    while(i<n){
        if(s2[j]==s1[i]){
            i++;j++;
        }
        if (j == m) { 
            return i - m;
            j = v[j - 1]; 
        } 
        else if (i < n && s2[j] != s1[i]) {
            if (j == 0)          
                i++;
            else
                j = v[j - 1];  
        }
    }
}
int main(){
    string s1,s2;
    cin>>s2>>s1;
    int i=0,j=0,cnt=1;
    int k=0;
    if(s2.size()==0){
        cout<<-1;
        return 0;
    }
    if(s2.size()>s1.size()){
        j=kmp(s1,s2);
    }
    else{
        while (s2[j]!=s1[i]){
            j++;
        }
    }
    while(i<s1.size()){
        if(s2[j]==s1[i])j++,i++;
        else{
            cnt=-1;
            break;
        }
        if(j==s2.size()&&i<s1.size()){
            cnt++;
            j=0;
        }
    }
    cout<<cnt;   
    return 0;
}