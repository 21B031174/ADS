#include <iostream>
#include <vector>

using namespace std;

void f(string s2, vector<int> & vec){
    vec[0] = 0;                   
    int j = 0,i=1;
    while (i<s2.size()){
        if(s2[i]==s2[j]){   
            j++;
            vec[i++] = j;
        }
        else{                   
            if(j==0)vec[i++] = 0;
            else j = vec[j-1];
        }
    }
}


int main(){
    string s1,s2;
    cin>>s1>>s2;
    vector<int>vec2;
    int n = s1.size();
    int m = s2.size();
    int i=0,j=0;
    vector<int> vec(m);
    f(s2,vec); 
    while(i<n){
        if(s2[j]==s1[i]){i++;j++;} 

        if (j == m) { 
            vec2.push_back(i - m+1);
            j = vec[j - 1]; 
        } 
        else if (i < n && s2[j] != s1[i]) {
            if (j == 0)i++;
            else j = vec[j - 1];
        }
    }
    cout<<vec2.size()<<endl;
    for (int i=0;i<vec2.size();i++){
        cout<<vec2[i]<<" ";
    }
    return 0;
}