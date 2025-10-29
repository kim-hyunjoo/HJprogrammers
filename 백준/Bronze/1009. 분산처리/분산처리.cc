#include <bits/stdc++.h>
using namespace std;

int main() {
  long long T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int a, b;
    cin >> a >> b;

    int last = a % 10;
    for (int j = 1; j < b; j++) {
      last = (last * a) % 10;
    }
    if (last == 0) {
      cout << 10 << "\n";
    } else {
      cout << last << "\n";
    }
  }
  return 0;
}