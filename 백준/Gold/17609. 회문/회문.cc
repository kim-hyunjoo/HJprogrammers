#include <bits/stdc++.h>
using namespace std;

int isPalindrome(int left, int right, int count, string str) {
  while (left < right) {
    if (str[left] != str[right]) {
      if (count == 0) {
        if (isPalindrome(left + 1, right, 1, str) == 0 ||
            isPalindrome(left, right - 1, 1, str) == 0) {
          return 1;
        } else {
          return 2;
        }
      } else {
        return 2;
      }
    } else {
      left++;
      right--;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    string str;
    cin >> str;

    cout << isPalindrome(0, str.length() - 1, 0, str) << '\n';
  }
  return 0;
}