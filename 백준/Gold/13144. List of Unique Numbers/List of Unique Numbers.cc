#include <bits/stdc++.h>
using namespace std;

bool isVisited[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long N;
  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  fill_n(&isVisited[0], 100001, false);
  int left = 0, right = 0;
  long long answer = N * (N + 1) / 2;

  while (right < N) {
    if (isVisited[arr[right]]) {
      isVisited[arr[left++]] = false;
      answer -= N - right;
    } else {
      isVisited[arr[right++]] = true;
    }
  }

  cout << answer;
  return 0;
}