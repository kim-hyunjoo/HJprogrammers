#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int count = 0;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    vector<bool> check(26, false);
    bool flag = true;
    check[str[0] - 'a'] = true;
    for (int j = 1; j < str.length(); j++) {
      if (str[j - 1] == str[j]) continue;
      if (check[str[j] - 'a']) {
        flag = false;
        break;
      }
      check[str[j] - 'a'] = true;
    }
    if (flag) {
      count++;
    }
  }
  cout << count;
  return 0;
}