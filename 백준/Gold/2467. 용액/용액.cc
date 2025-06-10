#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> arr;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    arr.push_back(num);
  }

  int left = 0, right = N - 1, sum, answer_left, answer_right,
      min_sum = INT_MAX;

  while (left < right) {
    sum = arr[left] + arr[right];

    if (abs(sum) < min_sum) {
      min_sum = abs(sum);
      answer_left = arr[left];
      answer_right = arr[right];
    }
    if (sum < 0) {
      left++;
    } else if (sum > 0) {
      right--;
    } else {
      break;
    }
  }

  cout << answer_left << ' ' << answer_right;
  return 0;
}