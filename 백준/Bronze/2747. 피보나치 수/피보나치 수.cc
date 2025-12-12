#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<unsigned long long> v(n + 1);

  v[0] = 0;
  v[1] = 1;
  v[2] = 1;

  for (int i = 3; i <= n; i++) {
    v[i] = v[i - 1] + v[i - 2];
  }
  cout << v[n] << "\n";
  return 0;
}