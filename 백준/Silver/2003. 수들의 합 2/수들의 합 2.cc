#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<int> arr;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    arr.push_back(num);
  }

  int left = 0, right = 0, sum = 0, answer = 0;
  sum = arr[0];
  while (right < N) {
    if (sum >= M) {
      if (sum == M) answer++;
      sum -= arr[left++];
    } else {
      sum += arr[++right];
    }
  }

  cout << answer;
  return 0;
}