#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  if (str.length() == 1) str.insert(0, "0");
  string s = str;
  int count = 0;

  do {
    int sum = (str[0] - '0') + (str[1] - '0');
    string newStr = string(1, str[1]) + to_string(sum % 10);
    str = newStr;
    count++;
  } while (str != s);

  cout << count;
  return 0;
}
