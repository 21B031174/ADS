#include <algorithm> 
#include <iostream> 
#include <cassert> 
#include <climits> 
#include <string> 
#include <vector> 
#include <ctime> 
#include <list> 

#define fi(n)  for(int i = 0; i < (n); i++) 
#define fj(n)  for(int j = 0; j < (n); j++) 
#define fk(n)  for(int k = 0; k < (n); k++) 

using namespace std; 
 
long long n, m, a, b, c; 
long long arr2[1100][1100]; 
long long arr1[1100]; 


int main(){  
    cin >> n; 
    fi(n) fj(n) cin >> arr2[i][j]; 
    fi(n){
        cin >> arr1[i];
        arr1[i]--;
    }
    fk(n){ 
        fi(n){ 
            fj(n){ 
                if(arr2[arr1[i]][arr1[j]] > arr2[arr1[i]][arr1[k]] + arr2[arr1[k]][arr1[j]]){
                    arr2[arr1[i]][arr1[j]] = arr2[arr1[i]][arr1[k]] + arr2[arr1[k]][arr1[j]];
                } 
            } 
        } 
        long long ans = 0; 
        fi(k+1) fj(k+1){ 
            ans = max(ans, arr2[arr1[i]][arr1[j]]); 
        } 
        cout << ans << '\n'; 
    } 
    return 0; 
}