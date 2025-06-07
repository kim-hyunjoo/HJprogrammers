#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;  // 사람 수
  cin >> N;

  vector<int> left;
  for (int i = 0; i < N; i++) {
    int h;
    cin >> h;
    left.push_back(h);
  }

  vector<int> answer(N, 0);

  for (int i = 1; i <= N; i++) {
    int j = 0;
    int count = 0;
    while (count < left[i - 1]) {
      if (answer[j] == 0) {
        count++;
      }
      j++;
    }
    while (answer[j] != 0) {
      j++;
    }
    answer[j] = i;
  }

  for (int i = 0; i < N; i++) {
    cout << answer[i] << ' ';
  }

  return 0;
}