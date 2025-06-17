#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, d, k, c;
  cin >> N >> d >> k >> c;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  vector<int> count(d + 1, 0);
  int kind = 0;

  for (int i = 0; i < k; i++) {
    if (count[arr[i]] == 0) {
      kind++;
    }
    count[arr[i]]++;
  }

  int max_kind = kind + (count[c] == 0 ? 1 : 0);

  if (max_kind == k + 1) {
    cout << max_kind;
    return 0;
  }

  for (int i = 1; i < N; i++) {
    int out = arr[i - 1];
    int in = arr[(i + k - 1) % N];

    count[out]--;
    if (count[out] == 0) {
      kind--;
    }
    if (count[in] == 0) {
      kind++;
    }
    count[in]++;

    max_kind = max(max_kind, kind + (count[c] == 0 ? 1 : 0));
  }

  cout << max_kind;

  return 0;
}