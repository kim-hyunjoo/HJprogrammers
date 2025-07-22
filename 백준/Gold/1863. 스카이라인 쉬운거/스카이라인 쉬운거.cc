#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;

  stack<int> s;
  int answer = 0;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    while (!s.empty() && s.top() > y) {
      s.pop();
      answer++;
    }

    if ((s.empty() || s.top() < y) && y != 0) {
      s.push(y);
    }
  }

  answer += s.size();

  cout << answer;
  return 0;
}