#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n][4];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> arr[i][j];
        }
    }
    int cnt_1 = 1;
    int cnt_2 = pow(10, 9);
    int answer = pow(10, 9);
    while(cnt_1 <= cnt_2){
        int pos = cnt_1 + (cnt_2 - cnt_1)/2;
        int next = 0;
        for(int i = 0; i < n; i++){
            if(arr[i][0] <= pos && arr[i][1] <= pos && arr[i][2] <= pos && arr[i][3] <= pos){
                next++;
            }
        }
        if(next < k){
            cnt_1 = pos + 1;
        } else{
            answer = min(answer, pos);
            cnt_2 = pos - 1;
        }
    }
    cout << answer << " ";
    return 0;
}