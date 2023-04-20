#include <iostream>

using namespace std;
long long q=2*1e18;

char toChar(long long a,int i,long long sum){
    char k;
    long long p=1;
    for(int j=0;j<i;j++){
        p*=2;
    }
    if(i==0){
        k=char(a+97);
    }
    else{
        k=char((((a-sum)/p)+97)%q);
    }
    return k;
}

int main(){
    int n;cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    string s="";
    long long sum=0;
    for(int i=0;i<n;i++){
        s+=toChar(arr[i],i,sum);
        sum=arr[i]%q;
    }
    cout<<s;
}