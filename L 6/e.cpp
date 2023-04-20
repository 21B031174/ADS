#include <iostream>

using namespace std;
int arr[1000][1000];
int partition(int low, int high,int k){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; ++j){
        if(arr[j][k] > arr[pivot][k]){
            i++;
            swap(arr[i][k], arr[j][k]);
        }
    }
    swap(arr[i + 1][k], arr[pivot][k]);
    return i + 1;
}


void qsort(int low, int high,int k){
    if(low < high){
        int pivot = partition(low, high,k);
        qsort(low, pivot - 1,k);
        qsort(pivot + 1, high,k);
    }
}

int main(){
    int n,m,a;cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        qsort(0,n-1,i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// 1 2 3 