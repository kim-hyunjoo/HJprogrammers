#include <bits/stdc++.h>
using namespace std;

int main() {
  // 코드 작성
  vector<int> v(3);
  for (int i = 0; i < 3; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  cout << v[1];
  return 0;
}