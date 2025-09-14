#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<bool> v(31, false);
  for (int i = 0; i < 28; i++) {
    int n;
    cin >> n;
    v[n] = true;
  }

  int count = 0;
  for (int i = 1; i <= 30; i++) {
    if (count == 2) break;
    if (!v[i]) {
      cout << i << '\n';
      count++;
    }
  }
  return 0;
}