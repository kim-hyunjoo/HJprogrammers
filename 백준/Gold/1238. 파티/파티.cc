#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > graph[1001];
int dist[1001][1001];  // s, x까지의 거리

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

void dijkstra(int v) {
  priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
  pq.push(make_pair(v, 0));

  while (!pq.empty()) {
    int start = pq.top().first;
    int curW = pq.top().second;
    pq.pop();

    for (int i = 0; i < graph[start].size(); i++) {
      int end = graph[start][i].first;
      int nextW = graph[start][i].second;

      if (curW + nextW < dist[v][end]) {
        dist[v][end] = curW + nextW;
        pq.push(make_pair(end, curW + nextW));
      }
    }
  }
}

int main() {
  // 코드 작성
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M, X;
  cin >> N >> M >> X;

  for (int i = 0; i < M; i++) {
    int s, e, t;
    cin >> s >> e >> t;
    graph[s].push_back(make_pair(e, t));
  }

  // 거리 배열 초기화
  fill_n(&dist[0][0], 1001 * 1001, INT_MAX);
  for (int i = 1; i <= N; i++) {
    dist[i][i] = 0;
  }

  // 각 s 마다 x까지의 거리를 계산해서 .... 각자 dist배열이 있어야할듯
  //  그렇게 계산해서 거기서 최대값을 구하기
  int answer = 0;
  dijkstra(X);
  for (int i = 1; i <= N; i++) {
    dijkstra(i);
  }

  for (int i = 1; i <= N; i++) {
    answer = max(dist[i][X] + dist[X][i], answer);
  }

  cout << answer;

  return 0;
}