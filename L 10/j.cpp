#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> g[100001];
bool ok[100001];
int cnt = 0;

map<int, int> mp;
map<int, int> mp2;

void bfs(int v) {
    queue<int> Q;
    Q.push(v);
    ok[v] = true;
    while(Q.size() > 0){
        queue<int> q;
        while (Q.size() > 0) { 
            q.push(Q.front());
            Q.pop();
        }

        while (q.size() > 0) {
            int x = q.front();
            q.pop();
            int globalCnt = 0;
            for (auto cnt: g[x]) {
                if (ok[cnt] == false) {
                    globalCnt++;
                }
            }
            mp2[x] = globalCnt;

            for (auto to: g[x]) {
                if (ok[to] == false){
                    mp[to] = x;
                    Q.push(to);
                    ok[to] = true;
                }
            }
        }
    }
}

bool check(int i, int j) {
    return (mp2[i] > mp2[j]);
}

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++){ 
        if (ok[i] == false) {
            cnt++;
            bfs(i);
        }
    }

    for (auto i: mp) {
        if (check(i.first, i.second)) {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}