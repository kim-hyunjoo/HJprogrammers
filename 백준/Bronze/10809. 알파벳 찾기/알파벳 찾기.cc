#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;

  for (char c = 'a'; c <= 'z'; c++) {
    int pos = str.find(c);
    if (pos == string::npos) {
      pos = -1;
    }
    cout << pos << ' ';
  }

  return 0;
}