#include <bits/stdc++.h>
using namespace std;

int N;
int mp[100][100];
bool isVisited[100][100];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int h, int curR, int curC) {
  isVisited[curR][curC] = true;
  for (int i = 0; i < 4; i++) {
    int nextR = curR + dr[i];
    int nextC = curC + dc[i];

    if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) continue;
    if (isVisited[nextR][nextC]) continue;
    if (mp[nextR][nextC] <= h) continue;

    dfs(h, nextR, nextC);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int maxH = 0;

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      cin >> mp[r][c];
      maxH = max(maxH, mp[r][c]);
    }
  }

  int answer = 0;

  for (int h = 0; h <= maxH; h++) {
    fill_n(&isVisited[0][0], 100 * 100, false);

    int count = 0;

    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        if (isVisited[r][c] == false && mp[r][c] > h) {
          dfs(h, r, c);
          count++;
        }
      }
    }

    answer = max(answer, count);
  }

  cout << answer;

  return 0;
}