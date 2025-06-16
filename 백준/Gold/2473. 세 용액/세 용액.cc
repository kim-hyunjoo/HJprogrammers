#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  vector<long long> arr;
  for (int i = 0; i < N; i++) {
    long long num;
    cin >> num;
    arr.push_back(num);
  }

  sort(arr.begin(), arr.end());

  int left = 0;
  long long min_answer = LLONG_MAX;
  int answer_left, answer_mid, answer_right;
  long long sum;

  for (int left = 0; left < arr.size() - 2; left++) {
    int mid = left + 1;
    int right = arr.size() - 1;

    while (mid < right) {
      sum = arr[left] + arr[mid] + arr[right];

      if (abs(sum) < min_answer) {
        min_answer = abs(sum);
        answer_left = arr[left];
        answer_mid = arr[mid];
        answer_right = arr[right];
      }

      if (sum < 0) {
        mid++;
      } else if (sum > 0) {
        right--;
      } else {
        cout << answer_left << ' ' << answer_mid << ' ' << answer_right;
        return 0;
      }
    }
  }

  cout << answer_left << ' ' << answer_mid << ' ' << answer_right;

  return 0;
}