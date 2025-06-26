#include <bits/stdc++.h>
using namespace std;

int N;
int mp[25][25];
bool isVisited[25][25];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

pair<int, int> findStart() {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (mp[r][c] == 1 && isVisited[r][c] == false) {
        return {r, c};
      }
    }
  }

  return {-1, -1};
}

int dfs(int curR, int curC) {
  isVisited[curR][curC] = true;
  int count = 1;
  for (int i = 0; i < 4; i++) {
    int nextR = curR + dr[i];
    int nextC = curC + dc[i];

    if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) continue;
    if (isVisited[nextR][nextC]) continue;
    if (mp[nextR][nextC] == 0) continue;

    count += dfs(nextR, nextC);
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  fill_n(&isVisited[0][0], 25 * 25, false);

  cin >> N;

  for (int r = 0; r < N; r++) {
    string str;
    cin >> str;
    for (int c = 0; c < N; c++) {
      mp[r][c] = str[c] - '0';
    }
  }

  // 시작점 찾기

  vector<int> answer;
  while (true) {
    auto [startR, startC] = findStart();
    if (startR == -1) break;

    int count = dfs(startR, startC);
    answer.push_back(count);
  }

  cout << answer.size() << '\n';
  sort(answer.begin(), answer.end());
  for (int n : answer) {
    cout << n << '\n';
  }

  return 0;
}