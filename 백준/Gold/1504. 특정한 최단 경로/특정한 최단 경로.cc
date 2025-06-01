#include <bits/stdc++.h>
using namespace std;
#define INF 2400000
struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

vector<int> dijkstra(vector<vector<pair<int, int> > > &graph, int startV,
                     int N) {
  vector<int> dist(N + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;

  pq.push(make_pair(startV, 0));
  dist[startV] = 0;

  while (!pq.empty()) {
    int curV = pq.top().first;
    int curW = pq.top().second;
    pq.pop();

    if (dist[curV] < curW) continue;

    for (int i = 0; i < graph[curV].size(); i++) {
      int nextV = graph[curV][i].first;
      int nextW = graph[curV][i].second;

      if (curW + nextW < dist[nextV]) {
        dist[nextV] = curW + nextW;
        pq.push(make_pair(nextV, curW + nextW));
      }
    }
  }
  return dist;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, E;
  cin >> N >> E;

  vector<vector<pair<int, int> > > graph(N + 1);

  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }

  int v1, v2;
  cin >> v1 >> v2;

  // 1->v1->v2->N 또는 1->v2->v1->N
  vector<int> dist1 = dijkstra(graph, 1, N);
  int s_to_v1 = dist1[v1];
  int s_to_v2 = dist1[v2];

  vector<int> dist2 = dijkstra(graph, v1, N);
  int v1_to_v2 = dist2[v2];  // 양방향이라 v2->v1과 동일
  int v1_to_N = dist2[N];

  vector<int> dist3 = dijkstra(graph, v2, N);
  int v2_to_N = dist3[N];

  int answer = v1_to_v2 + min(s_to_v1 + v2_to_N, s_to_v2 + v1_to_N);

  if (answer >= INF) {
    cout << -1;
  } else {
    cout << answer;
  }

  return 0;
}