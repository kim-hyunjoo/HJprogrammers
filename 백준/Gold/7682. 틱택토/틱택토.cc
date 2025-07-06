#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while (true) {
    string input;
    cin >> input;

    if (input == "end") break;

    bool isValid = true;

    int x_count = 0;
    int o_count = 0;

    for (int i = 0; i < 9; i++) {
      if (input[i] == 'X') x_count++;
      if (input[i] == 'O') o_count++;
    }

    // 만약 x와 o의 개수가 1개 차이거나 같지 않다면 invalid
    if (!(x_count == o_count || x_count == o_count + 1)) {
      isValid = false;
    }

    bool isSuccess_x = false;
    bool isSuccess_o = false;

    // 가로 세로 중 완성된게 있는지 체크
    for (int r = 0; r < 3; r++) {
      string row, col;
      row = string() + input[r * 3] + input[r * 3 + 1] + input[r * 3 + 2];
      col = string() + input[r] + input[r + 3] + input[r + 6];

      if (row == "XXX" || col == "XXX") isSuccess_x = true;
      if (row == "OOO" || col == "OOO") isSuccess_o = true;
    }

    // 대각선 중 완성된게 있는지 체크
    string cross;
    cross = string() + input[0] + input[4] + input[8];

    if (cross == "XXX") isSuccess_x = true;
    if (cross == "OOO") isSuccess_o = true;

    cross = string() + input[2] + input[4] + input[6];
    if (cross == "XXX") isSuccess_x = true;
    if (cross == "OOO") isSuccess_o = true;

    // o가 성공했는데 x개수가 더 많으면 invalid
    if (isSuccess_o && x_count > o_count) isValid = false;
    // x가 성공했는데 x개수가 o보다 1개 더 많지 않다면 invalid
    if (isSuccess_x && x_count != o_count + 1) isValid = false;

    // 만약 둘다 성공하지 않았는데 빈칸이 존재한다면 invalid
    if (!isSuccess_o && !isSuccess_x) {
      for (int i = 0; i < 9; i++) {
        if (input[i] == '.') {
          isValid = false;
        }
      }
    }

    cout << (isValid ? "valid" : "invalid") << '\n';
  }

  return 0;
}