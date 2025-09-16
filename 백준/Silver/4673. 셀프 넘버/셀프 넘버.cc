#include <bits/stdc++.h>
using namespace std;

int main() {
  set<int> s;
  for (int i = 1; i <= 10000; i++) {
    string str = to_string(i);
    int sum = i;
    for (char c : str) {
      sum += c - '0';
    }
    s.insert(sum);
    if (s.find(i) == s.end()) {
      cout << i << '\n';
    }
  }
  return 0;
}