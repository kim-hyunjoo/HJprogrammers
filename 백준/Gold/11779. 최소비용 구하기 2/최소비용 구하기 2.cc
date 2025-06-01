#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

void dijkstra(vector<vector<pair<int, int> > > &graph, int start, int end,
              int n) {
  vector<int> dist(n + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
  vector<int> path;
  unordered_map<int, int> mp;  // k: 현재노드 v: 직전 노드

  pq.push(make_pair(start, 0));

  while (!pq.empty()) {
    int curV = pq.top().first;
    int curW = pq.top().second;
    pq.pop();

    if (dist[curV] < curW) continue;

    for (auto el : graph[curV]) {
      int nextV = el.first;
      int nextW = el.second;

      if (curW + nextW < dist[nextV]) {
        dist[nextV] = curW + nextW;
        pq.push(make_pair(nextV, dist[nextV]));

        mp[nextV] = curV;
      }
    }
  }

  int v = end;
  path.push_back(end);

  while (v != start) {
    path.push_back(mp[v]);
    v = mp[v];
  }

  cout << dist[end] << '\n';
  cout << path.size() << '\n';
  for (int i = path.size() - 1; i >= 0; i--) {
    cout << path[i] << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int> > > graph(n + 1);

  for (int i = 0; i < m; i++) {
    int s, e, w;
    cin >> s >> e >> w;
    graph[s].push_back(make_pair(e, w));
  }

  int start, end;
  cin >> start >> end;

  dijkstra(graph, start, end, n);

  return 0;
}