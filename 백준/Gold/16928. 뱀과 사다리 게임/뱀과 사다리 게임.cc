#include <bits/stdc++.h>
using namespace std;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<int> graph(101, 0);

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    graph[x] = y;
  }

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    graph[u] = v;
  }

  // 현재 위치, 이동한 횟수
  // priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  queue<pair<int, int>> q;
  bool visit[101];
  fill_n(&visit[0], 101, false);

  q.push({1, 0});
  visit[1] = true;

  int answer = 0;

  while (!q.empty()) {
    const auto& [cur, count] = q.front();
    q.pop();

    if (cur == 100) {
      answer = count;
      break;
    }

    for (int i = 1; i <= 6; i++) {
      int next = cur + i;
      if (graph[next]) {
        next = graph[next];
      }

      if (next > 100) continue;
      if (visit[next]) continue;

      q.push({next, count + 1});
      visit[next] = true;
    }
  }

  cout << answer;

  return 0;
}