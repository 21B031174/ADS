#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long m,n,a;cin>>m>>n;
    long long arr[n];
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for(long long i=0;i<n;i++){
        long long l = -1, r = n+1;
        while(l+1<r){
            long long mid = (l+r)/2;
            if((arr[i]+arr[mid])>m){
                r = mid;
            }
            else if((arr[i]+arr[mid])<m){
                l = mid;
            }
            else{
                if(arr[i]>arr[mid]){
                    swap(arr[i],arr[mid]);
                }
                cout<<arr[i]<<" "<<arr[mid];
                return 0;
            }
        }
    }
}