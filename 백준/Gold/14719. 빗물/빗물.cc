#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int H, W;
  cin >> H >> W;

  vector<int> blocks(W);
  for (int i = 0; i < W; i++) {
    cin >> blocks[i];
  }

  int answer = 0;
  for (int i = 1; i < W - 1; i++) {
    int left = 0, right = 0;
    for (int j = 0; j < i; j++) {
      left = max(left, blocks[j]);
    }
    for (int j = i + 1; j < W; j++) {
      right = max(right, blocks[j]);
    }
    answer += max(0, min(left, right) - blocks[i]);
  }

  cout << answer;

  return 0;
}