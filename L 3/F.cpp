#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int bs(int a[], int n, int x){
	int l = 0;
	int r = n - 1;
	int mid;
	int res = -1;

	while(l <= r){
		mid = l + (r - l)/ 2;

		if(x < a[mid]){
			res = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	return res;
}

int ts(int a[], int pos){
	int sum = 0;
	for(int i=0; i<pos; i++)
		sum += a[i];
	return sum;
}

int main(){

	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a + n);

	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		int x;
		cin >> x;

		if(x < a[0]){
			cout << 0 << ' ' << 0 << endl;
			continue;
		}
		if(x >= a[n-1]){
			cout << n << ' ' << ts(a, n) << endl;
			continue;
		}

		int cnt = bs(a, n, x);
		int sum = ts(a, cnt);
		cout << cnt << ' ' << sum << endl;
	} 
	return 0; 

}