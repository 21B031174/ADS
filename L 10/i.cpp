#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 1;

vector <int> g[N];
vector <int> vec(N);

bool ok[N];

bool chek = true;

void dfs(int k, int v, int & i){
    ok[v] = 1;
    for(auto pk : g[v]){
        if(!ok[pk]){
            dfs(k, pk, i);
        }
        else{
            if(pk == k){chek = false;return;}
        }
    }
    vec[i] = v;
    i--;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        x--;y--;
        g[x].push_back(y);
    }
    int id = n-1;
    for(int i=0; i<n; i++){
        if(!ok[i])dfs(i, i, id);
        if(!chek)break;
    }
    if(chek){
        cout << "Possible" << '\n';
        for(int i=0; i<n; i++)cout << vec[i] + 1 << ' ';
    }
    else{
        cout << "Impossible";
    }
    return 0;
}