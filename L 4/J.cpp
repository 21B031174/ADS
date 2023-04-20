#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void chek(vector <int> arr){
    vector <int> arr1;
    vector <int> arr2;
    for(int i=0;i<arr.size()/2;i+=1){
        arr1.push_back(arr[i]);
        arr2.push_back(arr[arr.size()-1-i]);
    }
    cout<<arr[arr.size()/2]<<" ";
    
    if(arr1.size()==1){
        cout<<arr1[0]<<" ";
    }
    if(arr2.size()==1){
        cout<<arr2[0]<<" ";
    }
    if(arr1.size()!=1){
        chek(arr1); 
    }
    if(arr2.size()!=1){
        chek(arr2);
    }
    
    
}


int main(){
    int n;cin>>n;
    int z = pow(2,n)-1;
    vector <int> arr;
    vector <int> copy;
    for(int i=0;i<z;i+=1){
        int b;cin>>b;
        arr.push_back(b);
    }
    if(n==1){
        cout<<arr[0];
    }
    else{
        sort(arr.begin(),arr.end());
        chek(arr);
    }
    
    
    
    return 0;
}