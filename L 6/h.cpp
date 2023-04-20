#include <iostream>

using namespace std;

int partition(char * a, int low, int high){
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


void qsort(char * a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main(){
    int n;cin>>n;
    char s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    qsort(s, 0, n - 1);
    char k;cin>>k;
    for(int i = 0; i < n; ++i){
        if(int(s[i])>int(k)){
            cout<<s[i];
            return 0;
        }
    }
    cout<<s[0];

    return 0;
}