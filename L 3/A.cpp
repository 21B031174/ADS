#include <iostream>
using namespace std;
int n,m;
int arr[1000][1000];
void binary_search(int x){
    bool ok = false;
    for(int i=0;i<n;i++){
        int l = -1;
        int r = m+1;
        while (r-1!=l)
        {   
            int mid = (l+r)/2;
            if(i%2==0){
                if(arr[i][mid]<x){
                    r = mid;
                }
                else if(arr[i][mid]>x){
                    l = mid;
                }
                else{
                    ok = true;
                    cout<<i<<" "<<mid<<endl;
                    return;
                }
            }
            else{
                if(arr[i][mid]>x){
                    r = mid;
                }
                else if(arr[i][mid]<x){
                    l = mid;
                }
                else{
                    ok = true;
                    cout<<i<<" "<<mid<<endl;
                    return;
                }
            }
        }
    }
    if(!ok)cout<<-1<<endl;
}
int main(){
    int z;cin>>z;
    int arr2[z];
    for(int i=0;i<z;i+=1){cin>>arr2[i];}
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<z;i+=1){
        binary_search(arr2[i]);
    }
}