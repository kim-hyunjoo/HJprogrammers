#include <bits/stdc++.h>
using namespace std;

int mp[505][505];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  fill_n(&mp[0][0], 505 * 505, 0);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> mp[i][j];
    }
  }

  int answer = 0;

  // 1-1
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= M - 4; j++) {
      int own = mp[i][j];
      int two = mp[i][j + 1];
      int three = mp[i][j + 2];
      int four = mp[i][j + 3];

      answer = max(answer, own + two + three + four);
    }
  }

  // 1-2
  for (int i = 0; i <= N - 4; i++) {
    for (int j = 0; j < M; j++) {
      int own = mp[i][j];
      int two = mp[i + 1][j];
      int three = mp[i + 2][j];
      int four = mp[i + 3][j];

      answer = max(answer, own + two + three + four);
    }
  }

  // 2
  for (int i = 0; i <= N - 2; i++) {
    for (int j = 0; j <= M - 2; j++) {
      int own = mp[i][j];
      int two = mp[i + 1][j];
      int three = mp[i][j + 1];
      int four = mp[i + 1][j + 1];

      answer = max(answer, own + two + three + four);
    }
  }

  // 3-1
  for (int i = 0; i <= N - 3; i++) {
    for (int j = 0; j <= M - 2; j++) {
      int own = mp[i][j];
      int two = mp[i + 1][j];
      int three = mp[i + 2][j];
      int four = mp[i + 2][j + 1];

      answer = max(answer, own + two + three + four);

      own = mp[i][j + 1];
      two = mp[i + 1][j + 1];
      three = mp[i + 2][j + 1];
      four = mp[i + 2][j];

      answer = max(answer, own + two + three + four);
    }
  }

  // 3-2
  for (int i = 0; i <= N - 2; i++) {
    for (int j = 0; j <= M - 3; j++) {
      int own = mp[i + 1][j];
      int two = mp[i + 1][j + 1];
      int three = mp[i + 1][j + 2];
      int four = mp[i][j + 2];

      answer = max(answer, own + two + three + four);

      own = mp[i][j];
      two = mp[i + 1][j];
      three = mp[i + 1][j + 1];
      four = mp[i + 1][j + 2];

      answer = max(answer, own + two + three + four);
    }
  }

  // 3-3
  for (int i = 0; i <= N - 3; i++) {
    for (int j = 0; j <= M - 2; j++) {
      int own = mp[i][j];
      int two = mp[i][j + 1];
      int three = mp[i + 1][j + 1];
      int four = mp[i + 2][j + 1];

      answer = max(answer, own + two + three + four);

      own = mp[i][j];
      two = mp[i + 1][j];
      three = mp[i + 2][j];
      four = mp[i][j + 1];

      answer = max(answer, own + two + three + four);
    }
  }

  // 3-4
  for (int i = 0; i <= N - 2; i++) {
    for (int j = 0; j <= M - 3; j++) {
      int own = mp[i][j];
      int two = mp[i][j + 1];
      int three = mp[i][j + 2];
      int four = mp[i + 1][j];

      answer = max(answer, own + two + three + four);

      own = mp[i][j];
      two = mp[i][j + 1];
      three = mp[i][j + 2];
      four = mp[i + 1][j + 2];

      answer = max(answer, own + two + three + four);
    }
  }

  // 4-1
  for (int i = 0; i <= N - 3; i++) {
    for (int j = 0; j <= M - 2; j++) {
      int own = mp[i][j];
      int two = mp[i + 1][j];
      int three = mp[i + 1][j + 1];
      int four = mp[i + 2][j + 1];

      answer = max(answer, own + two + three + four);

      own = mp[i][j + 1];
      two = mp[i + 1][j + 1];
      three = mp[i + 1][j];
      four = mp[i + 2][j];

      answer = max(answer, own + two + three + four);
    }
  }

  // 4-2
  for (int i = 0; i <= N - 2; i++) {
    for (int j = 0; j <= M - 3; j++) {
      int own = mp[i + 1][j];
      int two = mp[i + 1][j + 1];
      int three = mp[i][j + 1];
      int four = mp[i][j + 2];

      answer = max(answer, own + two + three + four);

      own = mp[i][j];
      two = mp[i][j + 1];
      three = mp[i + 1][j + 1];
      four = mp[i + 1][j + 2];

      answer = max(answer, own + two + three + four);
    }
  }

  // 5-1
  for (int i = 0; i <= N - 2; i++) {
    for (int j = 0; j <= M - 3; j++) {
      int own = mp[i][j];
      int two = mp[i][j + 1];
      int three = mp[i][j + 2];
      int four = mp[i + 1][j + 1];

      answer = max(answer, own + two + three + four);

      own = mp[i][j + 1];
      two = mp[i + 1][j];
      three = mp[i + 1][j + 1];
      four = mp[i + 1][j + 2];

      answer = max(answer, own + two + three + four);
    }
  }

  // 5-2
  for (int i = 0; i <= N - 3; i++) {
    for (int j = 0; j <= M - 2; j++) {
      int own = mp[i][j];
      int two = mp[i + 1][j];
      int three = mp[i + 2][j];
      int four = mp[i + 1][j + 1];

      answer = max(answer, own + two + three + four);

      own = mp[i + 1][j];
      two = mp[i][j + 1];
      three = mp[i + 1][j + 1];
      four = mp[i + 2][j + 1];

      answer = max(answer, own + two + three + four);
    }
  }

  cout << answer;

  return 0;
}
