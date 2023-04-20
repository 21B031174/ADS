#include <iostream>

using namespace std;

int main(){
    int a;cin>>a;
    int arr[a];
    for (int i=0;i<a;i++){
        cin>>arr[i];
    }
    for(int i=0;i<a;i++){
        int l=0,r=i,res=i;
        while(l<=r){
            int mid = (r+l)/2;
            if(arr[i]-arr[mid]<=3000){
                res = mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cout<<i+1-res<<" ";
    }
}


//   1 5 7 12 34 45 64 71 70 83 86 90 97 101 120