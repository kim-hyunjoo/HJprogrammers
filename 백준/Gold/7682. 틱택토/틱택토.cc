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

    if (!(x_count == o_count || x_count == o_count + 1)) {
      isValid = false;
    }

    bool isSuccess_x = false;
    bool isSuccess_o = false;

    for (int r = 0; r < 3; r++) {
      string str1 = "", str2 = "";
      str1 = string() + input[r * 3] + input[r * 3 + 1] + input[r * 3 + 2];
      str2 = string() + input[r] + input[r + 3] + input[r + 6];

      if (str1 == "XXX" || str2 == "XXX") isSuccess_x = true;
      if (str1 == "OOO" || str2 == "OOO") isSuccess_o = true;
    }

    string str3 = "";
    // cout << input[0] << input[4] << input[8] << endl;
    str3 = string() + input[0] + input[4] + input[8];
    // cout << str3 << endl;
    if (str3 == "XXX") isSuccess_x = true;
    if (str3 == "OOO") isSuccess_o = true;
    str3 == "";
    str3 = string() + input[2] + input[4] + input[6];
    if (str3 == "XXX") isSuccess_x = true;
    if (str3 == "OOO") isSuccess_o = true;

    if (isSuccess_o && x_count > o_count) isValid = false;
    if (isSuccess_x && x_count != o_count + 1) isValid = false;

    // cout << isSuccess_o << isSuccess_x << endl;
    if (!isSuccess_o && !isSuccess_x) {
      for (int i = 0; i < 9; i++) {
        if (input[i] == '.') {
          isValid = false;
        }
      }
    }

    cout << (isValid ? "valid" : "invalid") << '\n';
  }
  /*
// invalid: x가 너무 많음 무조건 x는 o랑 같거나 1개 더 많음
 xxx
 oo
 xxx
// valid
 xox
 oxo
 xox
// invalid: o가 더 많음
 oxo
 xox
 oxo
//valid : 무승부
 xxo
 oox
 xox
//valid: x가 완성됨
 xo
 ox
   x
// invalid: o가 완성됐는데 x를 어케 더둠?
  xx
 x x
 ooo
// invalid: 아직 게임 더 진행 가능함
 x o
 o
 x
// invalid: x가 더 적음
 oox
 xxo
 oxo

 O.X.XOX..
 o x
  xo
 x
  */
  return 0;
}