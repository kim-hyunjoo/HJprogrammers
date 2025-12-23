#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> basket(N + 1);
  for (int i = 1; i <= N; i++) {
    basket[i] = i;
  }
  for (int t = 0; t < M; t++) {
    int i, j;
    cin >> i >> j;
    swap(basket[i], basket[j]);
  }
  for (int i = 1; i <= N; i++) {
    cout << basket[i] << " ";
  }
  return 0;
}