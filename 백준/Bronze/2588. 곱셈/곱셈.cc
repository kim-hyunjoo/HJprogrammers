#include <bits/stdc++.h>
using namespace std;

int main() {
  int num1;
  string num2;
  cin >> num1 >> num2;

  int sum = 0;
  for (int i = 0; i < num2.length(); i++) {
    char c = num2[num2.length() - i - 1];
    int digit = c - '0';
    cout << num1 * digit << "\n";

    sum += num1 * digit * pow(10, i);
  }
  {
    cout << sum << "\n";
  }

  return 0;
}