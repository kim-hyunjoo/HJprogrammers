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

  sort(arr.begin(), arr.end());

  int left = 0;
  int right = arr.size() - 1;
  int sum = arr[left] + arr[right];
  int min_sum = INT_MAX;
  int answer_left;
  int answer_right;

  while (left < right) {
    sum = arr[left] + arr[right];
    if (abs(sum) < min_sum) {
      min_sum = abs(sum);
      answer_left = arr[left];
      answer_right = arr[right];
    }
    if (abs(arr[left]) < abs(arr[right])) {
      sum -= arr[right--];
    } else if (abs(arr[left]) > abs(arr[right])) {
      sum -= arr[left++];
    } else {
      break;
    }
  }

  cout << answer_left << ' ' << answer_right;
  return 0;
}