#include <bits/stdc++.h>
using namespace std;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, r;
  cin >> n >> m >> r;

  unordered_map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> mp[i];
  }

  vector<vector<pair<int, int>>> graph(n + 1);
  for (int i = 0; i < r; i++) {
    int s, e, w;
    cin >> s >> e >> w;
    graph[s].push_back({e, w});
    graph[e].push_back({s, w});
  }

  int answer = 0;
  for (int i = 1; i <= n; i++) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<int> dist(n + 1, INT_MAX);
    pq.push({i, 0});
    dist[i] = 0;

    while (!pq.empty()) {
      auto [curV, curW] = pq.top();
      pq.pop();

      if (curW > dist[curV]) continue;

      for (int j = 0; j < graph[curV].size(); j++) {
        auto [nextV, nextW] = graph[curV][j];
        if (curW + nextW < dist[nextV]) {
          dist[nextV] = curW + nextW;
          pq.push({nextV, curW + nextW});
        }
      }
    }

    int sum = 0;
    for (int j = 1; j <= n; j++) {
      if (dist[j] <= m) {
        sum += mp[j];
      }
    }

    answer = max(answer, sum);
  }

  cout << answer;

  return 0;
}