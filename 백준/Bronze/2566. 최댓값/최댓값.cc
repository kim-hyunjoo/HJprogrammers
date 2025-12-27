#include <bits/stdc++.h>
using namespace std;

int main() {
  // 코드 작성
  int map[10][10];
  int max_value = -1;
  int max_row = 0;
  int max_col = 0;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> map[i][j];
      if (map[i][j] > max_value) {
        max_value = map[i][j];
        max_row = i;
        max_col = j;
      }
    }
  }

  cout << max_value << "\n";
  cout << max_row + 1 << " " << max_col + 1 << "\n";

  return 0;
}