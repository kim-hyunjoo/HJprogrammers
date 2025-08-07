#include <bits/stdc++.h>
using namespace std;

int mp[1500][1500];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < N * N; i++) {
    int x;
    cin >> x;
    pq.push(x);

    if (pq.size() > N) {
      pq.pop();
    }
  }

  cout << pq.top();

  return 0;
}