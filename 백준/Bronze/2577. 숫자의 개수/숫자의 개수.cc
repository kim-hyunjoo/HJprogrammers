#include <iostream>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int result = A * B * C;
  string str = to_string(result);

  for (int i = 0; i < 10; i++) {
    int count = 0;
    for (char c : str) {
      if ((c - '0') == i) {
        count++;
      }
    }
    cout << count << '\n';
  }

  return 0;
}