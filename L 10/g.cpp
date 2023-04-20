#include <iostream> 
#include <vector> 
#include <stack> 
#include <algorithm> 
using namespace std; 
 
vector<int> g[501]; 
int used[501]; 
stack<int> st; 
vector<int> vec; 
 
bool dfs(int v, int a, int b) { 
    used[v] = 1; 
    for (int i = 0; i < g[v].size(); i++) { 
        int to = g[v][i]; 
        if (v == a && b == to) continue; 
        if (!used[to]) { 
            if (dfs(to, a, b)) return true; 
        } else if (used[to] == 1) { 
            return true; 
        } 
    } 
    used[v] = 2; 
    return false; 
} 
 
bool dfs2(int v) { 
    used[v] = 1; 
    st.push(v); 
    for (int i = 0; i < g[v].size(); i++) { 
        int to = g[v][i]; 
        if (!used[to]) { 
            if (dfs2(to)) return true; 
        } else if (used[to] == 1) { 
            while (st.top() != to) { 
                vec.push_back(st.top()); 
                st.pop(); 
            } 
            vec.push_back(to); 
            vec.push_back(v); 
            reverse(vec.begin(), vec.end()); 
            return true; 
        } 
    } 
    used[v] = 2; 
    if (!st.empty()) st.pop(); 
    return false; 
} 
 
int main() { 
    int n, m; 
    cin >> n >> m; 
    for (int i = 0; i < m; i++) { 
        int u, v; cin >> u >> v; 
        g[u].push_back(v); 
    } 
    bool ok = false; 
    for (int i = 1; i <= n; i++) { 
        if (!used[i]) { 
            ok = dfs2(i); 
            if(ok)break; 
        } 
    } 
    if (!ok) { 
        cout << "YES" << endl; 
        return 0; 
    } 
 
    for (int i = 0; i < vec.size() - 1; i++) { 
        int u = vec[i]; 
        int v = vec[i + 1]; 
        for (int j = 1; j <= n; j++) { 
            used[j] = 0; 
        } 
        ok = 0; 
        for (int j = 1; j <= n; j++) { 
            if (!used[j]) { 
                ok |= dfs(j, u, v); 
            } 
        } 
        if (!ok) { 
            cout << "YES" << endl; 
            return 0; 
        } 
    } 
 
    cout << "NO" << endl; 
}