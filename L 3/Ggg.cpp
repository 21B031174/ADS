#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a,b;cin>>a>>b;
    int arr[a];
    
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    sort(arr, arr+a);
    int max = arr[a-1];
    int l=0;
    int r = max;
    int ans;
    int mid;
    bool ok = true;
    
    while(l!=r){
        mid  = l + (r-l)/2;
        int sum=0;
        for(int i=0;i<a;i++){
            sum += (arr[i]+mid-1)/mid;
        }

        if(sum>=b){
            l = mid;
        }
        else{r=mid;}
    }
    cout<<ans;

}