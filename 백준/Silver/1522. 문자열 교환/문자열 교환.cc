#include <bits/stdc++.h>
using namespace std;

int main() {
  ;
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string str;
  cin >> str;

  int a_count = 0;
  int b_count = 0;

  for (char c : str) {
    if (c == 'a') {
      a_count++;
    } else {
      b_count++;
    }
  }

  int count = 0;

  for (int i = 0; i < a_count; i++) {
    if (str[i] == 'b') {
      count++;
    }
  }

  int a_answer = count;

  for (int i = 1; i < str.length() - a_count; i++) {
    if (str[i - 1] == 'b') {
      count--;
    }
    if (str[i + a_count - 1] == 'b') {
      count++;
    }
    a_answer = min(a_answer, count);
  }

  count = 0;

  for (int i = 0; i < b_count; i++) {
    if (str[i] == 'a') {
      count++;
    }
  }

  int b_answer = count;

  for (int i = 1; i < str.length() - b_count; i++) {
    if (str[i - 1] == 'a') {
      count--;
    }
    if (str[i + b_count - 1] == 'a') {
      count++;
    }
    b_answer = min(b_answer, count);
  }

  cout << min(a_answer, b_answer);

  return 0;
}