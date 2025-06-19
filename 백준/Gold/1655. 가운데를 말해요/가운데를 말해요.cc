#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int> > right;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (left.size() <= right.size()) {
      left.push(num);
    } else {
      right.push(num);
    }
    if (i != 0 && left.top() > right.top()) {
      int left_tmp = left.top();
      int right_tmp = right.top();
      left.pop();
      right.pop();
      left.push(right_tmp);
      right.push(left_tmp);
    }

    if (left.size() > right.size()) {
      cout << left.top() << '\n';
    } else if (left.size() < right.size()) {
      cout << right.top() << '\n';
    } else {
      if (left.top() < right.top()) {
        cout << left.top() << '\n';
      } else {
        cout << right.top() << '\n';
      }
    }
  }
  return 0;
}