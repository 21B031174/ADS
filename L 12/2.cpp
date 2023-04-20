#include <iostream>
#include <vector>
#include <set>
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(a) a.begin() , a.end()
#define F first
#define S second
 
using namespace std;


const int N = 2e5+5 , inf = 2e9 + 7;
const long long INF = 1e18 ,   mod = 1e9+7 , P = 6547;

vector<pair<int,int> > g[N];
int n , m;

vector<int> fvector(int v) {
	vector<int> d(n+1, inf);
	d[v] = 0;
	set<pair<int,int> > st;
	st.insert(make_pair(0, v));
	while(st.size()) {
		pair<int,int> pr = *st.begin();
		st.erase(pr);
		for(auto to: g[pr.S]) {
			if(d[pr.S]+to.S < d[to.F]) {
				st.erase(make_pair(d[to.F], to.F));
				d[to.F] = d[pr.S]+to.S;
				st.insert(make_pair(d[to.F], to.F));
			}
		}
	}
	return d;
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b,c));
		g[b].push_back(make_pair(a,c));
	}
	int s,a,b,f;
	cin >> s>>a>>b>>f;
	vector<int> d1 = fvector(s);
	vector<int> d2 = fvector(a);
	vector<int> d3 = fvector(b);
	vector<int> d4 = fvector(f);
	int cnt = min(d1[a] + d2[b] + d3[f] , d1[b]+d3[a]+d2[f]);
	if(cnt > inf || cnt <-P) cnt = -1;
	cout << cnt;
}

