#include <bits/stdc++.h>
using namespace std;

struct cmp {
  bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second > b.second;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int C, R;
  cin >> C >> R;

  int maze[100][100];
  for (int r = 0; r < R; r++) {
    string str;
    cin >> str;
    for (int c = 0; c < C; c++) {
      maze[r][c] = str[c] - '0';
    }
  }

  int dist[100][100];
  fill_n(&dist[0][0], 100 * 100, INT_MAX);
  int dr[4] = {1, 0, -1, 0};
  int dc[4] = {0, 1, 0, -1};

  priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >,
                 cmp>
      pq;
  pq.push(make_pair(make_pair(0, 0), 0));
  dist[0][0] = 0;

  while (!pq.empty()) {
    int curR = pq.top().first.first;
    int curC = pq.top().first.second;
    int curW = pq.top().second;
    pq.pop();

    for (int i = 0; i < 4; i++) {
      int nextR = curR + dr[i];
      int nextC = curC + dc[i];

      if (nextR < 0 || nextC < 0 || nextR >= R || nextC >= C) continue;

      if (curW + maze[nextR][nextC] < dist[nextR][nextC]) {
        dist[nextR][nextC] = curW + maze[nextR][nextC];
        pq.push(make_pair(make_pair(nextR, nextC), dist[nextR][nextC]));
      }
    }
  }

  cout << dist[R - 1][C - 1];

  return 0;
}