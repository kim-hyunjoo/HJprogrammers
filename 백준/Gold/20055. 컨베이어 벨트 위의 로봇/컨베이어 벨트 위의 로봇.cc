#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  vector<pair<int, bool> > belt;  // 내구도, 로봇 존재 여부
  for (int i = 1; i <= 2 * N; i++) {
    int A;
    cin >> A;
    belt.push_back(make_pair(A, false));
  }

  int zeros = 0;
  int answer = 1;

  while (true) {
    // 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
    auto el = belt[2 * N - 1];
    belt.erase(belt.end() - 1);
    belt.insert(belt.begin(), el);

    // 로봇 하차
    if (belt[N - 1].second) {
      belt[N - 1].second = false;
    }

    // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸
    // 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
    for (int i = N - 2; i >= 0; i--) {
      if (!belt[i].second) continue;

      // 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며,
      // 그 칸의 내구도가 1 이상 남아 있어야 한다.
      if (!belt[i + 1].second && belt[i + 1].first > 0) {
        belt[i].second = false;
        belt[i + 1].first--;
        belt[i + 1].second = true;

        // 내구도 체크
        if (belt[i + 1].first == 0) {
          zeros++;
        }
        // 로봇 하차
        if (i + 1 == N - 1) {
          belt[i + 1].second = false;
        }
      }
    }

    if (belt[0].first > 0) {
      belt[0].first--;
      belt[0].second = true;

      // 내구도 체크
      if (belt[0].first == 0) {
        zeros++;
      }
    }

    if (zeros >= K) {
      cout << answer;
      break;
    }

    answer++;
  }

  return 0;
}