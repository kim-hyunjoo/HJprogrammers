#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<long long> arr;
  for (int i = 0; i < N; i++) {
    long long num;
    cin >> num;
    arr.push_back(num);
  }

  sort(arr.begin(), arr.end());

  int left = 0;
  int right = 0;
  long long gap;
  long long min_gap = LLONG_MAX;
  while (right < N) {
    gap = arr[right] - arr[left];
    if (gap >= M && gap < min_gap) {
      min_gap = gap;
    }
    if (gap < M) {
      right++;
    } else if (gap > M) {
      left++;
    } else {
      break;
    }
  }

  cout << min_gap;
  return 0;
}