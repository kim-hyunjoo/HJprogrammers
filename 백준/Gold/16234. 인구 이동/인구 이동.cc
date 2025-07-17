#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int A[50][50];
bool isVisited[50][50];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
vector<pair<int, int>> unions;

void dfs(int r, int c) {
  unions.push_back({r, c});
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
    if (isVisited[nr][nc]) continue;
    if (abs(A[r][c] - A[nr][nc]) < L || abs(A[r][c] - A[nr][nc]) > R) continue;
    isVisited[nr][nc] = true;
    dfs(nr, nc);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> L >> R;

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      cin >> A[r][c];
    }
  }

  int answer = 0;

  while (true) {
    fill_n(&isVisited[0][0], 50 * 50, false);
    vector<vector<pair<int, int>>> unionsArr;

    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        if (isVisited[r][c]) continue;
        unions.clear();
        isVisited[r][c] = true;
        dfs(r, c);
        if (unions.size() >= 2) {
          unionsArr.push_back(unions);
        }
      }
    }

    if (unionsArr.size() == 0) break;

    for (auto& unions : unionsArr) {
      int sum = 0;
      for (auto& country : unions) {
        int value = A[country.first][country.second];
        sum += value;
      }
      int avg = sum / unions.size();
      for (auto& country : unions) {
        A[country.first][country.second] = avg;
      }
    }

    answer++;
  }

  cout << answer;

  return 0;
}