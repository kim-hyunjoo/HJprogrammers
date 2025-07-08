#include <bits/stdc++.h>
using namespace std;

int dp[10000];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  vector<int> nums(T);
  int max_n = 0;

  for (int t = 0; t < T; t++) {
    cin >> nums[t];
    max_n = max(max_n, nums[t]);
  }

  dp[1] = 1;  // 1
  dp[2] = 2;  // 1+1, 2
  dp[3] = 3;  // 1+1+1, 1+2, 3

  for (int i = 4; i <= max_n; i++) {
    dp[i] = 1 + i / 2 + dp[i - 3];
  }

  for (int num : nums) {
    cout << dp[num] << '\n';
  }

  return 0;
}