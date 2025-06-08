#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, D;
  cin >> N >> D;

  vector<int> dp(D + 1, 10001);

  vector<vector<pair<int, int> > > graph(10001);

  for (int i = 0; i < N; i++) {
    int s, e, w;
    cin >> s >> e >> w;
    graph[e].push_back(make_pair(s, w));
  }

  dp[0] = 0;
  for (int i = 1; i <= D; i++) {
    if (graph[i].size() == 0) {
      dp[i] = dp[i - 1] + 1;
    } else {
      for (auto e : graph[i]) {
        dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[e.first] + e.second));
      }
    }
  }

  cout << dp[D];

  return 0;
}