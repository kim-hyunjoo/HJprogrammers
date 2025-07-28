#include <bits/stdc++.h>
using namespace std;

int R, C;
string mp[21];
bool visited[26];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int answer = 0;

void dfs(int r, int c, int count) {
  answer = max(answer, count);
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;

    int alpha = mp[nr][nc] - 'A';
    if (visited[alpha]) continue;

    visited[alpha] = true;
    dfs(nr, nc, count + 1);
    visited[alpha] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    cin >> mp[i];
  }

  visited[mp[0][0] - 'A'] = true;
  dfs(0, 0, 1);

  cout << answer;

  return 0;
}