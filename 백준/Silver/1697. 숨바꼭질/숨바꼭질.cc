#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int answer = 0;
  int N, K;
  cin >> N >> K;

  int dn[3] = {-1, 1, 2};
  queue<pair<int, int> > q;
  vector<bool> isVisited(100001, false);

  q.push({N, 0});

  while (!q.empty()) {
    const auto& [curN, depth] = q.front();
    q.pop();

    if (curN == K) {
      answer = depth;
      break;
    }

    int nextN;
    for (int i = 0; i < 3; i++) {
      if (i == 2) {
        nextN = curN * 2;
      } else {
        nextN = curN + dn[i];
      }

      if (nextN < 0 || nextN > 100000) {
        continue;
      }
      if (isVisited[nextN]) {
        continue;
      }

      isVisited[nextN] = true;
      q.push({nextN, depth + 1});
    }
  }

  cout << answer;
  return 0;
}