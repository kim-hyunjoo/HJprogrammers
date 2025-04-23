#include <bits/stdc++.h>
using namespace std;

void DFS() {}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M, V;  // 정점의 개수, 간선의 개수, 탐색 시작 점
  cin >> N >> M >> V;

  vector<vector<int> > graph(N + 1);

  // 그래프 그리기
  for (int i = 0; i < M; i++) {
    int start, end;
    cin >> start >> end;
    graph[start].push_back(end);
    graph[end].push_back(start);
  }

  // 정렬
  for (int i = 1; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  bool isVisited[N + 1];
  fill_n(&isVisited[0], N + 1, false);

  /* DFS */

  stack<int> s;
  // 탐색 시작 지점
  s.push(V);
  isVisited[V] = true;
  cout << V << ' ';

  while (!s.empty()) {
    int curV = s.top();
    bool exist_child = false;

    // 현재 정점에서 탐색 가능한 자식 노드 1개 찾기
    for (int i = 0; i < graph[curV].size(); i++) {
      int nextV = graph[curV][i];
      if (!isVisited[nextV]) {
        cout << nextV << ' ';
        s.push(nextV);
        isVisited[nextV] = true;
        // 찾으면 중단하고 바로 그 노드에서 새로 탐색
        exist_child = true;
        break;
      }
    }

    // 더이상 자식 노드가 없다면 스택에서 제거
    if (!exist_child) {
      s.pop();
    }
  }

  cout << '\n';

  // 방문여부 배열 초기화
  fill_n(&isVisited[0], N + 1, false);

  /* BFS */

  queue<int> q;
  // 탐색 시작 지점
  q.push(V);
  isVisited[V] = true;

  while (!q.empty()) {
    int curV = q.front();
    q.pop();
    cout << curV << ' ';

    for (int i = 0; i < graph[curV].size(); i++) {
      int nextV = graph[curV][i];
      // 방문하지 않은 인접 노드를 전부 큐에 삽입
      if (!isVisited[nextV]) {
        isVisited[nextV] = true;
        q.push(nextV);
      }
    }
  }

  return 0;
}