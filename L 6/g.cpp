#include <iostream>

using namespace std;
string arr[10][2];
int a;
void Pair(){
    bool ok=true;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(arr[i][1]==arr[j][0] and arr[i][1]!=arr[i][0]){
                arr[i][1]=arr[j][1];
                ok=false;
                swap(arr[j],arr[a-1]);
                a--;
                break;
            }
        }
    }
    if(!ok){
        Pair();
    }
}

int partition(int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j < high; ++j){
        if(arr[j][0] < arr[pivot][0]){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pivot]);
    return i + 1;
}


void qsort(int low, int high){
    if(low < high){
        int pivot = partition(low, high);
        qsort(low, pivot - 1);
        qsort(pivot + 1, high);
    }
}

int main(){
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    Pair();
    qsort(0,a-1);
    cout<<a<<endl;
    for(int i=0;i<a;i++){
        cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    }
}