#include <iostream>
#include <vector>
using namespace std;

int partition(int * a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; ++j){
        if(a[j] < a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}


void qsort(int * a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main(){

    int n,m;cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    qsort(arr1, 0, n - 1);
    qsort(arr2, 0, m - 1);
    int i=0,j=0,k=-1;
    while(i<n){
        j = k+1;
        while(j<m){
            if(arr1[i] == arr2[j]){
                cout<<arr1[i]<<" ";
                k=j;
                break;
            }
            j++;
        }
        i++;
    }

    return 0;
}