#include <bits/stdc++.h>
using namespace std;

int N, C;

bool isPossible(vector<long long> &house, int dist) {
  int count = 1;
  int last = house[0];

  for (int i = 1; i < house.size(); i++) {
    if (house[i] - last >= dist) {
      last = house[i];
      count++;
    }
  }

  return count >= C;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> C;

  vector<long long> house(N);
  for (int i = 0; i < N; i++) {
    cin >> house[i];
  }

  sort(house.begin(), house.end());

  if (N == 2) {
    cout << house[1] - house[0];
    return 0;
  }

  int left = 1;
  int right = house[N - 1] - house[0];
  int answer = 0;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (isPossible(house, mid)) {
      answer = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << answer;
  return 0;
}