#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  vector<int> v(t);
  for (int i = 0; i < t; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  cout << v[0] * v[v.size() - 1];

  return 0;
}