#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

int right_(int arr[], int g, int k, int r){
    int sum = k + (r-k)/2;
    if(k == sum){
        return sum;
    }
    if(arr[sum] <= g){
        return right_(arr, g, sum, r);
    } else{
        return right_(arr, g, k, sum);
    }
}
int left_(int arr[], int x, int l, int r){
    int m = l + (r-l)/2;
    if(l == m){
        return m + 1;
    }
    if(arr[m] >= x){
        return left_(arr, x, l, m);
    } else{
        return left_(arr, x, m, r);
    }
}
int binary_(int arr[], int l, int r, int x, int y){
    int leva = left_(arr, x, l, r);
    int prava = right_(arr, y, l, r);
    int answer = (prava-leva) + 1;
    return answer;
}
int main(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for(int i = 0; i < m; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 <=l2 && r2 <= r1){
            cout << binary_(arr, -1, n, l1, r1) << endl;
        } else if(l2 <= l1 && r1 <= r2){
            cout << binary_(arr, -1, n, l2, r2) << endl;
        } else if(l1 <= l2 && l2 <= r1){
            cout << binary_(arr, -1, n, l1, r2) << endl;
        } else if(l2 <= l1 && l1 <= r2){
            cout << binary_(arr, -1, n, l2, r1) << endl;
        } else{
            cout << binary_(arr, -1, n, l1, r1) + binary_(arr, -1, n, l2, r2) << endl;
        }
    }
    return 0;
}