#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<char>> board(5, vector<char>(15, '\0'));
  for (int i = 0; i < 5; i++) {
    string str;
    cin >> str;

    for (int j = 0; j < str.length(); j++) {
      board[i][j] = str[j];
    }
  }
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 5; j++) {
      if (board[j][i] != '\0') {
        cout << board[j][i];
      }
    }
  }
  return 0;
}