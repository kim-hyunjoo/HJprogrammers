#include <bits/stdc++.h>
using namespace std;

int mp[50][50];

int dr[4] = {-1, 0, 1, 0};  // 위 오른쪽 아래 왼쪽
int dc[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M, r, c, d;
  cin >> N >> M >> r >> c >> d;

  // 0: 청소되지 않은 빈칸
  // 1: 벽
  // 로봇 청소기 있는 칸은 항상 빈칸
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> mp[i][j];
    }
  }

  /*
  1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
  2. 현재 칸의 주변칸 중 청소되지 않은 빈 칸이 없는 경우,
        2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고
  1번으로 돌아간다.
        2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을
  멈춘다.
  3. 현재 칸의 주변 칸 중 청소되지 않은 빈 칸이 있는 경우,
        3-1. 반시계 방향으로 회전한다.
        3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한
  칸 전진한다.
        3-3. 1번으로 돌아간다.
  */

  int answer = 0;

  while (true) {
    if (mp[r][c] == 0) {
      mp[r][c] = 2;
      answer++;
    }

    bool isMoved = false;

    for (int i = 0; i < 4; i++) {
      d = (d + 3) % 4;
      int nr = r + dr[d];
      int nc = c + dc[d];

      if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
      if (mp[nr][nc] == 0) {
        r = nr;
        c = nc;
        isMoved = true;
        break;
      }
    }

    if (!isMoved) {
      int nr = r + dr[(d + 2) % 4];
      int nc = c + dc[(d + 2) % 4];

      if (nr < 0 || nc < 0 || nr >= N || nc >= M) break;
      if (mp[nr][nc] == 1) break;

      r = nr;
      c = nc;
    }
  }

  cout << answer;

  return 0;
}