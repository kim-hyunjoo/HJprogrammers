#include <iostream>
using namespace std;

int main() {
  // 코드 작성
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int H, W, N;
    cin >> H >> W >> N;
    int a = N % H;
    if (a == 0) a = H;
    int b = (N - 1) / H + 1;
    string str = "";
    str += to_string(a);
    if (b < 10) {
      str += "0" + to_string(b);
    } else {
      str += to_string(b);
    }
    cout << str << '\n';
  }
  return 0;
}