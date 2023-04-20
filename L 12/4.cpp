#include <iostream>
#include <vector>

using namespace std;
int n;
pair <long long, long long> aPair[1000];

long long arr[1000][1000];

long long func(long long arr2[], bool sparr3[]){
    long long min = 9223372036854775807;
    long long valMin;

    for(int i = 0; i < n; i++){
        if(!sparr3[i] && min > arr2[i]){
            min = arr2[i];
            valMin = i;
        }
    }

    return valMin;
}

int main(){

    cin >> n;
    long long a, b;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        aPair[i] = make_pair(a, b);
        for(int j = 0; j <= i; j++){
            arr[i][j] = abs(a - aPair[j].first) + abs(b - aPair[j].second);
            arr[j][i] = arr[i][j];
        }
    }

    long long arr2[n];
    bool arr3[n];

    for(int i = 0; i < n; i++){
        arr2[i] = 9223372036854775807;
        arr3[i] = false;
    }

    arr2[0] = 0;
    for(int i = 0; i < n - 1; i++){
        int u = func(arr2, arr3);
        arr3[u] = true;
        for(int j = 0; j < n; j++){
            if(!arr3[j] &&  arr2[j] > max(arr2[u], arr[u][j])){
                    arr2[j] = max(arr2[u], arr[u][j]);
                }
        }
    }

    cout<<arr2[n - 1];

    return 0;
}