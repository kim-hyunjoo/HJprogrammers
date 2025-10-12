#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v(8);
  for (int i = 0; i < 8; i++) {
    cin >> v[i];
  }

  bool isAscending = true;
  for (int i = 1; i <= 8; i++) {
    if (i != v[i - 1]) {
      isAscending = false;
      break;
    }
  }

  if (isAscending) {
    cout << "ascending";
    return 0;
  }

  bool isDescending = true;
  for (int i = 8; i >= 1; i--) {
    if (i != v[8 - i]) {
      isDescending = false;
      break;
    }
  }

  if (isDescending) {
    cout << "descending";
    return 0;
  }

  cout << "mixed";

  return 0;
}