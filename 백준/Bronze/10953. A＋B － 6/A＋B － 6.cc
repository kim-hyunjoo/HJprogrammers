#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    string str;
    cin >> str;
    int a = str[0] - '0';
    int b = str[2] - '0';
    cout << a + b << "\n";
  }
  return 0;
}