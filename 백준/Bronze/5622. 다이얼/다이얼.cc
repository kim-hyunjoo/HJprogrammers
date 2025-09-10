#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;

  int answer = 0;
  for (char c : str) {
    int cur;
    switch (c) {
      case 'A':
      case 'B':
      case 'C':
        cur = 3;
        break;
      case 'D':
      case 'E':
      case 'F':
        cur = 4;
        break;
      case 'G':
      case 'H':
      case 'I':
        cur = 5;
        break;
      case 'J':
      case 'K':
      case 'L':
        cur = 6;
        break;
      case 'M':
      case 'N':
      case 'O':
        cur = 7;
        break;
      case 'P':
      case 'Q':
      case 'R':
      case 'S':
        cur = 8;
        break;
      case 'T':
      case 'U':
      case 'V':
        cur = 9;
        break;
      case 'W':
      case 'X':
      case 'Y':
      case 'Z':
        cur = 10;
        break;
    }
    answer += cur;
  }

  cout << answer;
  return 0;
}