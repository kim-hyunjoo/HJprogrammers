#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  int target;
  cin >> target;

  int count = 0;
  for (int i = 0; i < N; i++) {
    if (v[i] == target) {
      count++;
    }
  }

  cout << count;
  return 0;
}