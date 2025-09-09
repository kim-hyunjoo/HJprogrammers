#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  stack<int> s;

  for (int i = 0; i < N; i++) {
    string cmd;
    int num;
    cin >> cmd;
    if (cmd == "push") {
      cin >> num;
    }

    if (cmd == "push") {
      s.push(num);
    }

    else if (cmd == "pop") {
      if (s.empty()) {
        cout << -1 << '\n';
      } else {
        int x = s.top();
        cout << x << '\n';
        s.pop();
      }
    } else if (cmd == "size") {
      cout << s.size() << '\n';
    } else if (cmd == "empty") {
      cout << s.empty() << '\n';
    } else if (cmd == "top") {
      if (s.empty()) {
        cout << -1 << '\n';
      } else {
        int x = s.top();
        cout << x << '\n';
      }
    }
  }
  return 0;
}