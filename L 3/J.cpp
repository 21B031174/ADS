#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 1000001

int n, k, a[MAX];

bool check(int x){
    int f = 0;
    double p;
    for(int i = 0; i < n; i++){
        p = a[i];
        p = p / x;
        f += ceil(p);
    }
    return f <= k;
}

int bs(int mx){
    int left = 0;
    int right = mx;
    int mid;
    while(true){
        mid = left + (right - left)/ 2;
        if(check(mid)){
            right = mid;
        }else 
            left = mid;
        if(right - left == 1)
            return right;
    }
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int mx = a[0];
    cout << bs(1000000001);
}