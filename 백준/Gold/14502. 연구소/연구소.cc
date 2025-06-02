#include <bits/stdc++.h>
using namespace std;

int mp[8][8];
int N, M;

int bfs(vector<pair<int, int> > &walls, vector<pair<int, int> > &virus) {
  int dr[4] = {1, 0, -1, 0};
  int dc[4] = {0, 1, 0, -1};

  queue<pair<int, int> > q;

  // 추가 벽 설치
  int newMap[8][8];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      newMap[i][j] = mp[i][j];
    }
  }
  for (auto pos : walls) {
    newMap[pos.first][pos.second] = 1;
  }

  // 바이러스 위치부터 탐색 시작
  for (auto pos : virus) {
    q.push(pos);
  }

  while (!q.empty()) {
    int curR = q.front().first;
    int curC = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextR = curR + dr[i];
      int nextC = curC + dc[i];

      if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M ||
          newMap[nextR][nextC] != 0) {
        continue;
      }

      newMap[nextR][nextC] = 2;
      q.push(make_pair(nextR, nextC));
    }
  }

  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (newMap[i][j] == 0) {
        count++;
      }
    }
  }

  return count;
}

// 바이러스는 2~10개 사이로 주어짐
// 벽은 총 3개 세우기 가능
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  // 벽 세울 수 있는 좌표
  vector<pair<int, int> > pos;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> mp[i][j];
      if (mp[i][j] == 0) {
        pos.push_back(make_pair(i, j));
      }
    }
  }

  vector<vector<pair<int, int> > > comb;
  // 벽 세우기 후보
  for (int i = 0; i < pos.size() - 2; i++) {
    for (int j = i + 1; j < pos.size() - 1; j++) {
      for (int k = j + 1; k < pos.size(); k++) {
        vector<pair<int, int> > v;
        v.push_back(pos[i]);
        v.push_back(pos[j]);
        v.push_back(pos[k]);
        comb.push_back(v);
      }
    }
  }

  // 바이러스 위치
  vector<pair<int, int> > virus;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (mp[i][j] == 2) {
        virus.push_back(make_pair(i, j));
      }
    }
  }

  // 바이러스 퍼진 모양
  int answer = 0;
  for (vector<pair<int, int> > walls : comb) {
    answer = max(answer, bfs(walls, virus));
  }

  cout << answer;

  return 0;
}