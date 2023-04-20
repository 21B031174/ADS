#include <iostream>

using namespace std;

void merge(long long * a, long long l1, long long r1, long long l2, long long r2){
    long long n1 = r1 - l1 + 1;
    long long L[n1];
    for(long long i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
    }

    long long n2 = r2 - l2 + 1;
    long long R[n2];
    for(long long i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
    }

    long long i = l1;
    long long i1 = 0;
    long long i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(L[i1] < R[i2]){
            a[i++] = L[i1++];
        }else {
            a[i++] = R[i2++];
        }
    }
    
    //copy rest of L
    while(i1 < n1){
        a[i++] = L[i1++];
    }

    //copy rest of R
    while(i2 < n2){
        a[i++] = R[i2++];
    }

}

void msort(long long * a, long long l, long long r){
    if(l < r){
        long long m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m , m + 1, r);
    }
}

int main(){
    long long n,m;cin>>n;
    long long arr[1000000];    
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>m;
    for(long long i=n;i<n+m;i++){
        cin>>arr[i];
    }
    msort(arr, 0, n+m - 1);

    for(long long i = 0; i < n+m; ++i){
        cout << arr[i] << " ";
    }

    return 0;
}