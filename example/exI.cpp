#include <iostream>

using namespace std;

void bs(int arr[],int x,int size){
    int l=-1;
    int r=size+1;
    bool ok =true;
    while (l!=r-1 && ok)
    {
        int mid =(l+r)/2;
        if(x>arr[mid]){
            l=mid;
        }
        else if(x<arr[mid]){
            r=mid;
        }
        else{
            cout<<"Yes";
            ok = false;
            return;
            break;
            
        }
    }
    cout<<"No";
    return;
    
}



int main(){
    int a,b;cin>>a;
    int arr[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    cin>>b;
    bs(arr,b,a);

}