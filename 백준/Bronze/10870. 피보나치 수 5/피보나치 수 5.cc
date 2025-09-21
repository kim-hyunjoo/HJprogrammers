#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  if (N == 0) {
    cout << 0;
    return 0;
  }
  if (N == 1) {
    cout << 1;
    return 0;
  }
  int a = 0, b = 1;
  int c;
  for (int i = 2; i <= N; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  cout << c;
  return 0;
}