#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  if (N < 2) {
    cout << 0;
    return 0;
  }

  vector<bool> isPrime(N + 1, true);
  vector<int> arr;
  // 에라토스테네스의 체
  for (int i = 2; i <= N; i++) {
    if (isPrime[i]) {
      arr.push_back(i);
      for (long long j = (long long)1 * i * i; j <= N; j += i) {
        isPrime[j] = false;
      }
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