#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;

  int map[15][15] = {
      0,
  };

  for (int i = 1; i <= 14; i++) {
    map[0][i] = i;
    map[i][1] = 1;
  }

  for (int i = 0; i < T; i++) {
    int k, n;
    cin >> k >> n;
    int sum = 0;
    for (int f = 1; f <= k; f++) {
      for (int h = 2; h <= n; h++) {
        map[f][h] = map[f][h - 1] + map[f - 1][h];
      }
    }

    cout << map[k][n] << "\n";
  }
  return 0;
}
