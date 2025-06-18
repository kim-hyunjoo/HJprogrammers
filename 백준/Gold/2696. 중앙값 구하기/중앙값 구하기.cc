#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int M;
    cin >> M;

    vector<int> mid;

    // 중앙 값보다 작은 값
    priority_queue<int> left_pq;
    // 중앙 값보다 큰 값
    priority_queue<int, vector<int>, greater<int> > right_pq;

    for (int i = 0; i < M; i++) {
      int num;
      cin >> num;
      if (left_pq.size() <= right_pq.size()) {
        left_pq.push(num);
      } else {
        right_pq.push(num);
      }
      if (i != 0 && left_pq.top() > right_pq.top()) {
        int left_tmp = left_pq.top();
        int right_tmp = right_pq.top();
        left_pq.pop();
        right_pq.pop();
        left_pq.push(right_tmp);
        right_pq.push(left_tmp);
      }
      if (i % 2 == 0) {
        if (left_pq.size() > right_pq.size()) {
          mid.push_back(left_pq.top());
        } else {
          mid.push_back(right_pq.top());
        }
      }
    }
    cout << mid.size() << '\n';
    for (int i = 0; i < mid.size(); i++) {
      if (i != 0 && i % 10 == 0) {
        cout << '\n';
      }
      cout << mid[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}