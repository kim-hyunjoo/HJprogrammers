#include <bits/stdc++.h>
using namespace std;

int N, C;

bool install(vector<int> &houses, int dist) {
  int count = 1;
  int last = houses[0];
  for (int i = 1; i < houses.size(); i++) {
    if (last + dist <= houses[i]) {
      last = houses[i];
      count++;
    }
  }
  return count >= C;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> C;

  vector<int> houses(N);
  for (int i = 0; i < N; i++) {
    cin >> houses[i];
  }

  sort(houses.begin(), houses.end());

  int left = 1;
  int right = houses[N - 1] - houses[0];

  int answer = 0;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (install(houses, mid)) {
      answer = max(answer, mid);
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << answer;

  return 0;
}