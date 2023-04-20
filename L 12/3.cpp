#include <iostream>
#include <vector>
#include <queue> 
using namespace std; 

vector<int> vec1[410]; 
vector<int> vec2[410]; 

int arr[405][405]; 

int main(){ 
    int n,m; 
    cin >> n >> m; 
    for(int i=0;i<m;i++){ 
        int a,b; 
        cin >> a >> b; 
        a--; 
        b--; 
        vec1[a].push_back(b); 
        vec1[b].push_back(a); 
        
        arr[a][b] = 1; 
        arr[b][a] = 1; 
    } 
    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            if (arr[i][j] == 0 && i != j){ 
                vec2[i].push_back(j); 
            } 
        } 
    } 
    queue<int> que; 
    vector<int> vec3(n+1); 
    vector<bool> ok(n+1); 
    que.push(0); 
    ok[0] = true; 
    while(!que.empty()){ 
        int v = que.front(); 
        que.pop(); 
        for(int i=0;i<vec1[v].size();i++){ 
            int to = vec1[v][i]; 
            if(!ok[to]){ 
                ok[to] = true; 
                que.push(to); 
                vec3[to] = vec3[v]+1; 
            } 
        } 
    } 
    queue<int> que2; 
    vector<int> vec4(n+1); 
    vector<bool> ok2(n+1); 
    que2.push(0); 
    ok2[0] = true; 
    while(!que2.empty()){ 
        int v = que2.front(); 
        que2.pop(); 
        for(int i=0;i<vec2[v].size();i++){ 
            int to = vec2[v][i]; 
            if(!ok2[to]){ 
                ok2[to] = true; 
                que2.push(to); 
                vec4[to] = vec4[v]+1; 
            } 
        } 
    } 
    if (!ok[n-1] || !ok2[n-1]){ 
        cout << -1; 
    } 
    else { 
        cout << max(vec3[n-1], vec4[n-1]); 
    } 
}