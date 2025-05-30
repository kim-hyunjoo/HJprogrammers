#include <bits/stdc++.h>
using namespace std;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  int dx[3] = {1, -1, 2};
  priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
  vector<int> time(100001, INT_MAX);

  pq.push(make_pair(N, 0));
  time[N] = 0;

  while (!pq.empty()) {
    int curX = pq.top().first;
    int curTime = pq.top().second;
    pq.pop();

    for (int i = 0; i < 3; i++) {
      int nextX, nextTime;
      if (i == 2) {
        nextX = curX * 2;
        nextTime = time[curX];
      } else {
        nextX = curX + dx[i];
        nextTime = time[curX] + 1;
      }

      if (nextX < 0 || nextX > 100000) {
        continue;
      }

      if (time[nextX] > nextTime) {
        time[nextX] = nextTime;
        pq.push(make_pair(nextX, nextTime));
      }
    }
  }

  cout << time[K];

  return 0;
}