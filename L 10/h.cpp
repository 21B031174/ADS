#include <iostream>

using namespace std;

string str[101];
int n,m;
bool ok[101][101];

void dfs(int i, int j){
    ok[i][j] = true;
    if(i + 1 < n && !ok[i + 1][j] && str[i + 1][j] == '1'){
        dfs(i + 1, j);
    }
    if(i - 1 >= 0 && !ok[i - 1][j] && str[i - 1][j] == '1'){
        dfs(i - 1, j);
    }
    if(j + 1 < m && !ok[i][j + 1] && str[i][j + 1] == '1'){
        dfs(i, j + 1);
    }
    if(j - 1 >= 0 && !ok[i][j - 1] && str[i][j - 1] == '1'){
        dfs(i, j - 1);
    }
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;  j++){
            if(!ok[i][j] && str[i][j] == '1'){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}