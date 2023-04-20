#include <iostream>
#include <vector>

using namespace std;


const int constant = 1e9;

int main() {
	int n; cin >> n;
	int final = 0;
	vector<vector<int> > v(n);
	vector<bool> ok(n);
	vector<int> save(n,-1);
	vector<int> minim(n,constant);
	minim[0] = 0;
	for(int i=0;i<n;i++){
		v[i].resize(n);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)cin>>v[i][j];
	}
	for(int i=0;i<n;i++){
		int k = -1;
		for(int j=0;j<n;j++){
			if (minim[j] < minim[k] or k == -1){
				if(!ok[j])k = j;
			}
		}
		if (save[k] != -1) {
			final += v[k][save[k]];
		}
		for (int j = 0; j < n; j++) {
			if (minim[j] > v[k][j]) {
				save[j] = k;
				minim[j] = v[k][j];
			}
		}
		ok[k] = true;
	}
	cout << final;
}