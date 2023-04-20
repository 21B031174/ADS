#include <iostream>
using namespace std;

int main(){
    int a;cin>>a;
    int search[a];
    for(int i=0;i<a;i++){
        cin>>search[i];
    }
    int n,m;cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<a;i++){
        bool ok =true;
        for(int k=0;k<n;k++){
            int r=-1,l=m+1;
            while (r-1!=l)
            {
                int mid = (r+l)/2;
                if(k%2==0){
                    if(search[i]>arr[k][mid]){
                        r=mid;
                    }
                    else if(search[i]<arr[k][mid]){
                        l=mid;
                    }
                    else{
                        cout<<k<<" "<<mid<<endl;
                        ok = false;
                        break;
                    }
                }
                else{
                    if(search[i]<arr[k][mid]){
                        r=mid;
                    }
                    else if(search[i]>arr[k][mid]){
                        l=mid;
                    }
                    else{
                        cout<<k<<" "<<mid<<endl;
                        ok = false;
                        break;
                    }
                }
            } 
            if(ok == false){
                break;
            }      
        }
    }
}