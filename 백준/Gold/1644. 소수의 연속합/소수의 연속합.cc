#include <bits/stdc++.h>
using namespace std;

bool isPrimeNumber(int num) {
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  if (N < 2) {
    cout << 0;
    return 0;
  }

  vector<int> arr;

  for (int i = 2; i <= N; i++) {
    if (isPrimeNumber(i)) {
      arr.push_back(i);
    }
  }

  int left = 0, right = 0;
  int sum = arr[0];
  int answer = 0;

  while (left <= right) {
    if (sum == N) {
      answer++;
    }
    if (sum < N) {
      if (right == arr.size() - 1) break;
      sum += arr[++right];
    } else {
      sum -= arr[left++];
    }
  }

  cout << answer;

  return 0;
}