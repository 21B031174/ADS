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
    int a;cin>>a;
    int arr[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    qsort(arr, 0, a-1);
    long min=10000000;
    int k;
    for(int i=0;i<a-1;i++){
        if(min>=(arr[i+1]-arr[i])){
            min= (arr[i+1]-arr[i]);
        }
    }
    for(int i=0;i<a-1;i++){
        if(min==(arr[i+1]-arr[i])){
            cout<<arr[i]<<" "<<arr[i+1]<<" ";
        }
    }
}