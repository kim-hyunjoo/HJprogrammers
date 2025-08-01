#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string str, target;
  cin >> str >> target;

  string answer = "";
  for (char c : str) {
    answer.push_back(c);

    if (answer.length() < target.length()) continue;

    bool isBomb = true;
    for (int i = 0; i < target.length(); i++) {
      if (target[i] != answer[answer.length() - target.length() + i]) {
        isBomb = false;
        break;
      }
    }
    if (isBomb) {
      for (int i = 0; i < target.length(); i++) {
        answer.pop_back();
      }
    }
  }

  if (answer.length() == 0) {
    cout << "FRULA";
  } else {
    cout << answer;
  }

  return 0;
}