#include <iostream>
using namespace std;

int main() {
  string N;
  int B;
  cin >> N >> B;

  int result = 0;
  for (char c : N) {
    int digit;
    if (c >= '0' && c <= '9') {
      digit = c - '0';
    } else {
      digit = c - 'A' + 10;
    }

    result = result * B + digit;
  }
  cout << result << endl;
  return 0;
}