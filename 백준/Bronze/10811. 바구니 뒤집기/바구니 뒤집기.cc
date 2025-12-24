#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> baskets(N + 1);
  for (int i = 1; i <= N; i++) {
    baskets[i] = i;
  }
  for (int t = 0; t < M; t++) {
    int i, j;
    cin >> i >> j;
    for (int k = 0; k < (j - i + 1) / 2; k++) {
      swap(baskets[i + k], baskets[j - k]);
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << baskets[i] << " ";
  }

  return 0;
}