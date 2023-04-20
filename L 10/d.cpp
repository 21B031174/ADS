#include <iostream>
#include <vector>
#include <queue>
 
using namespace std; 
 
vector<int> g[5001]; 
bool isTrue[5001]; 
int d[5001]; 
int ok[5001]; 

int main() { 
    int n, m, q; 
    cin>>n>>m>>q;
    for (int i = 0; i < m; i++) { 
        int u, v; 
        cin >> u >> v; 
        g[u].push_back(v); 
        g[v].push_back(u); 
    } 
    for (int i = 1; i <= n; i++) { 
        d[i] = 2e9; 
    } 
    for (int t = 1; t <= q; t++) { 
        int a, v; 
        cin>>a>>v;
        if (a == 1) { 
            if (ok[v] != 1) { 
                for (int i = 1; i <= n; i++) { 
                    isTrue[i] = 0; 
                } 
                queue<int> q; 
                q.push(v); 
                d[v] = 0; 
                isTrue[v] = 1; 
                while (!q.empty()) { 
                    int v = q.front(); 
                    q.pop(); 
                    for (int i = 0; i < g[v].size(); i++) { 
                        int to = g[v][i]; 
                        if (d[to] > d[v] + 1) { 
                            d[to] = d[v] + 1; 
                            isTrue[to] = 1; 
                            q.push(to); 
                        } 
                    } 
                } 
                ok[v] = 1; 
            } 
        } else { 
            if (d[v] == 2e9) cout << -1 << endl; 
            else cout << d[v] << endl; 
        } 
    } 
    return 0;
}