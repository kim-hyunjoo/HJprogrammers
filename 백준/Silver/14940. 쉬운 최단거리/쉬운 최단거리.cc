#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int dr[4] = {1, 0, -1, 0};
  int dc[4] = {0, 1, 0, -1};

  int n, m;
  cin >> n >> m;

  int graph[1001][1001];
  int startR, startC;

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> graph[r][c];
      if (graph[r][c] == 2) {
        startR = r;
        startC = c;
      }
    }
  }

  queue<pair<int, int>> q;
  q.push({startR, startC});

  int distance[1001][1001];
  fill_n(&distance[0][0], 1001 * 1001, INT_MAX);

  distance[startR][startC] = 0;

  while (!q.empty()) {
    const auto& [curR, curC] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextR = curR + dr[i];
      int nextC = curC + dc[i];

      if (nextR < 0 || nextC < 0 || nextR >= n || nextC >= m) continue;
      if (distance[nextR][nextC] != INT_MAX) continue;

      if (graph[nextR][nextC] == 0) {
        distance[nextR][nextC] = 0;
      } else {
        distance[nextR][nextC] = distance[curR][curC] + 1;
        q.push({nextR, nextC});
      }
    }
  }

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (distance[r][c] == INT_MAX) {
        if (graph[r][c] == 0) {
          distance[r][c] = 0;
        } else {
          distance[r][c] = -1;
        }
      }
    }
  }

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cout << distance[r][c] << ' ';
    }
    cout << '\n';
  }

  return 0;
}