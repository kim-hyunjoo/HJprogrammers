#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<int> arr;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    arr.push_back(num);
  }

  sort(arr.begin(), arr.end());

  int left = 0;
  int right = 0;
  int gap;
  int min_gap = INT_MAX;
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