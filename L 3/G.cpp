#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

  int n, k;
  cin >> n >> k;
  int ar[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  int left = 1, right = 0, mid;
  for (int i = 0; i < n; i++) {
    right = max(right, ar[i]);
  }
  while (left < right) {
    mid = left + (right - left) / 2;
    int j = 0;
    for (int i = 0; i < n; i++) {
      j += (ar[i] + mid - 1) / mid;
    }
    if (k >= j) {
      right = mid;
    }
    else {
      left = mid + 1;
    }
  }
  cout << right;
  return 0;
} 