#include <bits/stdc++.h>
using namespace std;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

struct cmp {
  bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<2>(a) > get<2>(b);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int test_case = 1;
  while (true) {
    int N;
    cin >> N;
    if (N == 0) break;

    vector<vector<int> > mp(N, vector<int>(N));
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        cin >> mp[r][c];
      }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, cmp> pq;
    vector<vector<int> > dist(N, vector<int>(N, INT_MAX));

    pq.push(make_tuple(0, 0, mp[0][0]));
    dist[0][0] = mp[0][0];

    while (!pq.empty()) {
      int curR, curC, curW;
      tie(curR, curC, curW) = pq.top();
      pq.pop();

      if (curW > dist[curR][curC]) continue;

      for (int i = 0; i < 4; i++) {
        int nextR = curR + dr[i];
        int nextC = curC + dc[i];

        if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) continue;

        if (curW + mp[nextR][nextC] < dist[nextR][nextC]) {
          dist[nextR][nextC] = curW + mp[nextR][nextC];
          pq.push(make_tuple(nextR, nextC, curW + mp[nextR][nextC]));
        }
      }
    }

    cout << "Problem " << test_case++ << ": " << dist[N - 1][N - 1] << '\n';
  }
  return 0;
}