#include <iostream>
using namespace std;

int main() {
  while (true) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0) break;

    if (!(max(max(a, b), c) < (a + b + c - max(max(a, b), c)))) {
      cout << "Invalid" << '\n';
    } else if (a == b && b == c) {
      cout << "Equilateral" << '\n';
    } else if (a == b || b == c || a == c) {
      cout << "Isosceles" << '\n';
    } else {
      cout << "Scalene" << '\n';
    }
  }
  return 0;
}