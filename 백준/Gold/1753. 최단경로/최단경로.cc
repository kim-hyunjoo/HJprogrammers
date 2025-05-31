#include <bits/stdc++.h>
using namespace std;
#define MAX 20001

int dist[MAX];  // startV에서 각 정점까지의 최소 비용
vector<pair<int, int> > graph[MAX];

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

void dijkstra(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int> >, cmp>
      pq;  // 다음 탐색 정점, 가중치

  pq.push(make_pair(start, 0));

  while (!pq.empty()) {
    int curV = pq.top().first;
    int curW = pq.top().second;
    pq.pop();

    for (int i = 0; i < graph[curV].size(); i++) {
      int nextV = graph[curV][i].first;
      int nextW = graph[curV][i].second;
      if (curW + nextW < dist[nextV]) {
        dist[nextV] = curW + nextW;
        pq.push(make_pair(nextV, nextW + curW));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int V, E, startV;
  cin >> V >> E >> startV;

  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
  }

  // 거리 비용 초기화
  for (int i = 1; i <= V; i++) {
    dist[i] = INT_MAX;
  }
  dist[startV] = 0;

  dijkstra(startV);

  for (int i = 1; i <= V; i++) {
    if (dist[i] == INT_MAX) {
      cout << "INF" << '\n';
    } else {
      cout << dist[i] << '\n';
    }
  }

  return 0;
}