#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int> > &graph, int N, int X, int K) {
  queue<int> q;
  vector<int> dist(N + 1, INT_MAX);
  q.push(X);
  dist[X] = 0;

  while (!q.empty()) {
    int curV = q.front();
    q.pop();

    for (int i = 0; i < graph[curV].size(); i++) {
      int nextV = graph[curV][i];

      if (dist[curV] + 1 < dist[nextV]) {
        dist[nextV] = dist[curV] + 1;
        q.push(nextV);
      }
    }
  }

  vector<int> answer;
  for (int i = 1; i <= N; i++) {
    if (dist[i] == K) {
      answer.push_back(i);
    }
  }

  if (answer.size() != 0) {
    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << '\n';
    }
  } else {
    cout << -1;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M, K, X;
  cin >> N >> M >> K >> X;

  vector<vector<int> > graph(N + 1);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }

  dijkstra(graph, N, X, K);
  return 0;
}