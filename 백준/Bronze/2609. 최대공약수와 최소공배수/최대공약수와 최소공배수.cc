#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int num1 = 1;
  int num2 = 1;

  for (int i = 1; i < min(a, b) + 1; i++) {
    if (a % i == 0 && b % i == 0) {
      num1 = i;
    }
  }

  for (int i = max(a, b); i <= a * b; i++) {
    if (i % a == 0 && i % b == 0) {
      num2 = i;
      break;
    }
  }

  cout << num1 << "\n" << num2 << "\n";
  return 0;
}