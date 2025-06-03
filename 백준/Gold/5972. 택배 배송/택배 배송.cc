#include <bits/stdc++.h>
using namespace std;

int N, M;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

int dijkstra(vector<vector<pair<int, int> > > &graph) {
  vector<int> dist(N + 1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
  pq.push(make_pair(1, 0));
  dist[1] = 0;

  while (!pq.empty()) {
    int curV = pq.top().first;
    int curW = pq.top().second;
    pq.pop();

    if (curW > dist[curV]) continue;

    for (int i = 0; i < graph[curV].size(); i++) {
      int nextV = graph[curV][i].first;
      int nextW = graph[curV][i].second;

      if (curW + nextW < dist[nextV]) {
        dist[nextV] = curW + nextW;
        pq.push(make_pair(nextV, dist[nextV]));
      }
    }
  }

  return dist[N];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  vector<vector<pair<int, int> > > graph(N + 1);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }

  cout << dijkstra(graph);

  return 0;
}