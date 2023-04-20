#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int bs(int a[], int n, int x){
	int l = 0;
    int r = n-1;
    int m;
    int res = -1;

	while(l <= r){
		m = (l + r) / 2;

		if(x <= a[m]){
			res = m;
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}

	return res;
}

int main(){
	vector <int> v;
	int n, m, val = 1;
	cin >> n >> m;

	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(i)
			a[i] += a[i-1];
	}

	for(int i=0; i<m; i++){
		int x;
		cin >> x;

		cout << bs(a, n, x) + 1 << '\n';
	}
}