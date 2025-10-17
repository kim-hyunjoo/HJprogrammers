#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> v(N + 1, 0);
  for (int x = 0; x < M; x++) {
    int i, j, k;
    cin >> i >> j >> k;
    for (int s = i; s <= j; s++) {
      v[s] = k;
    }
  }

  for (int i = 1; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  return 0;
}