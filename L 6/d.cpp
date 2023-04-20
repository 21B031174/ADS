#include <iostream>
#include <vector>
using namespace std;

int partition(string * a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; ++j){
        if((int(a[j][6])-48)*1000+(int(a[j][7])-48)*100+(int(a[j][8])-48)*10+(int(a[j][9])-48)< (int(a[pivot][6])-48)*1000+(int(a[pivot][7])-48)*100+(int(a[pivot][8])-48)*10+(int(a[pivot][9])-48)){
            i++;
            swap(a[i], a[j]);
        }
        else if((int(a[j][6])-48)*1000+(int(a[j][7])-48)*100+(int(a[j][8])-48)*10+(int(a[j][9])-48) == (int(a[pivot][6])-48)*1000+(int(a[pivot][7])-48)*100+(int(a[pivot][8])-48)*10+(int(a[pivot][9])-48)){
            if((int(a[j][3])-48)*10+(int(a[j][4])-48) < (int(a[pivot][3])-48)*10+(int(a[pivot][4])-48)){
                i++;
                swap(a[i], a[j]);
            }
            else if((int(a[j][3])-48)*10+(int(a[j][4])-48) == (int(a[pivot][3])-48)*10+(int(a[pivot][4])-48)){
                if((int(a[j][0])-48)*10+(int(a[j][1])-48) < (int(a[pivot][0])-48)*10+(int(a[pivot][1])-48)){
                    i++;
                    swap(a[i], a[j]);
                }
            }
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}


void qsort(string * a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main(){
    int a;cin>>a;
    string arr[a];
    string s;
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    qsort(arr, 0, a-1);
    for(int i=0;i<a;i++){
        cout<<arr[i]<<endl;
    }
}