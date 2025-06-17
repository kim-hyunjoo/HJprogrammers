#include <bits/stdc++.h>
using namespace std;

int mp[100000][3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> mp[i][j];
    }
  }

  int min_dp[3];
  int max_dp[3];
  int min_tmp[3];
  int max_tmp[3];
  for (int j = 0; j < 3; j++) {
    min_dp[j] = max_dp[j] = mp[0][j];
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      min_tmp[j] = min_dp[j];
      max_tmp[j] = max_dp[j];
    }

    min_dp[0] = mp[i][0] + min(min_tmp[0], min_tmp[1]);
    max_dp[0] = mp[i][0] + max(max_tmp[0], max_tmp[1]);

    min_dp[1] = mp[i][1] + min(min(min_tmp[0], min_tmp[1]), min_tmp[2]);
    max_dp[1] = mp[i][1] + max(max(max_tmp[0], max_tmp[1]), max_tmp[2]);

    min_dp[2] = mp[i][2] + min(min_tmp[1], min_tmp[2]);
    max_dp[2] = mp[i][2] + max(max_tmp[1], max_tmp[2]);
  }

  int max_score = max(max(max_dp[0], max_dp[1]), max_dp[2]);
  int min_score = min(min(min_dp[0], min_dp[1]), min_dp[2]);

  cout << max_score << ' ' << min_score;

  return 0;
}