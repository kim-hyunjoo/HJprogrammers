#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, S;
  cin >> N >> S;

  vector<int> arr;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    arr.push_back(num);
  }

  int left = 0;
  int right = 0;
  int sum = arr[0];
  int answer = INT_MAX;
  while (right < N) {
    if (sum >= S) {
      answer = min(answer, right - left + 1);
      sum -= arr[left++];
    } else {
      sum += arr[++right];
    }
  }

  if (answer == INT_MAX) {
    cout << 0;
  } else {
    cout << answer;
  }

  return 0;
}