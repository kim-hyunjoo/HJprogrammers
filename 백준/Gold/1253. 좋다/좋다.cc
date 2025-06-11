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

  int answer = 0;

  for (int i = 0; i < N; i++) {
    int left = 0;
    int right = N - 1;
    if (left == i) {
      left++;
    }
    if (right == i) {
      right--;
    }

    while (left < right) {
      if (arr[left] + arr[right] == arr[i]) {
        answer++;
        break;
      } else if (arr[left] + arr[right] > arr[i]) {
        right--;
        if (right == i) {
          right--;
        }
      } else {
        left++;
        if (left == i) {
          left++;
        }
      }
    }
  }

  cout << answer;

  return 0;
}