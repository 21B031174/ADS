#include <iostream>
#include <vector>

using namespace std;

void print(vector <int> arr,int n){
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            if(arr[j]+arr[i]==n){
                cout<<arr[i]<<" "<<arr[j];
                return;
            }
        }
    }
}

bool isPrime(int x){
    for(int i=2;i*i<=x;i+=1){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;cin>>n;
    vector <int> arr;
    for(int i=2;i<=n;i+=1){
        if(isPrime(i)){
            arr.push_back(i);
        }
    }
    print(arr,n);
}