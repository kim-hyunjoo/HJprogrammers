#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int p, m;  // 플레이어 수, 방의 정원
  cin >> p >> m;

  unordered_map<string, int> players_level;  // 닉네임-레벨
  vector<vector<string> > rooms;

  for (int i = 0; i < p; i++) {
    int l;     // 레벨
    string n;  // 닉네임

    cin >> l >> n;
    players_level[n] = l;

    bool isEntered = false;

    // 들어갈 수 있는 방 탐색
    for (int j = 0; j < rooms.size(); j++) {
      string player = rooms[j][0];  // 기준이 되는
      int level = players_level[player];
      // 정원이 안차고 레벨 범위 안에 있다면 입장
      if (rooms[j].size() < m && l >= level - 10 && l <= level + 10) {
        rooms[j].push_back(n);
        isEntered = true;
        break;
      }
    }

    // 없으면 새로 방 만들어서 입장
    if (!isEntered) {
      vector<string> room;
      room.push_back(n);
      rooms.push_back(room);
    }
  }

  for (int j = 0; j < rooms.size(); j++) {
    sort(rooms[j].begin(), rooms[j].end());
    // 정원이 다 찬 경우
    if (rooms[j].size() == m) {
      cout << "Started!" << '\n';
      for (int k = 0; k < m; k++) {
        cout << players_level[rooms[j][k]] << ' ' << rooms[j][k] << '\n';
      }
    } else {
      cout << "Waiting!" << '\n';
      for (int k = 0; k < rooms[j].size(); k++) {
        cout << players_level[rooms[j][k]] << ' ' << rooms[j][k] << '\n';
      }
    }
  }

  return 0;
}