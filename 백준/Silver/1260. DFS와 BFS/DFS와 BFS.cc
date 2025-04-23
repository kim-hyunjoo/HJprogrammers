#include <bits/stdc++.h>
using namespace std;

void DFS() {}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M, V;  // 정점의 개수, 간선의 개수, 탐색 시작 점
  cin >> N >> M >> V;

  vector<vector<int> > graph(N + 1);

  for (int i = 0; i < M; i++) {
    int start, end;
    cin >> start >> end;
    graph[start].push_back(end);
    graph[end].push_back(start);
  }

  // 정렬
  for (int i = 1; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end(), greater<int>());
  }

  bool isVisited[N + 1];
  fill_n(&isVisited[0], N + 1, false);

  // DFS
  stack<int> s;
  s.push(V);

  while (!s.empty()) {
    int curV = s.top();
    s.pop();
    if (isVisited[curV]) {
      continue;
    }
    cout << curV << ' ';
    isVisited[curV] = true;

    for (int i = 0; i < graph[curV].size(); i++) {
      int nextV = graph[curV][i];
      if (!isVisited[nextV]) {
        s.push(nextV);
      }
    }
  }

  cout << '\n';

  // 다시 초기화
  fill_n(&isVisited[0], N + 1, false);

  for (int i = 1; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  // BFS
  queue<int> q;
  q.push(V);
  isVisited[V] = true;

  while (!q.empty()) {
    int curV = q.front();
    q.pop();
    cout << curV << ' ';

    for (int i = 0; i < graph[curV].size(); i++) {
      int nextV = graph[curV][i];

      if (!isVisited[nextV]) {
        isVisited[nextV] = true;
        q.push(nextV);
      }
    }
  }

  return 0;
}