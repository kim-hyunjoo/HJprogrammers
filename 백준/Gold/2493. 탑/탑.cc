#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  vector<int> towers(N);
  vector<int> answer(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> towers[i];
  }

  stack<pair<int, int>> s;
  s.push({towers[N - 1], N - 1});

  for (int i = N - 2; i >= 0; i--) {
    int tower = towers[i];
    if (tower >= s.top().first) {
      while (true) {
        if (s.empty()) break;
        if (tower < s.top().first) break;
        answer[s.top().second] = i + 1;
        s.pop();
      }
    }

    s.push({tower, i});
  }

  for (int n : answer) {
    cout << n << ' ';
  }

  return 0;
}