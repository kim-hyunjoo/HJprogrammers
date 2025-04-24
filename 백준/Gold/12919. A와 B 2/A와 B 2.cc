#include <bits/stdc++.h>
using namespace std;

void DFS(string S, string T) {
  if (S == T) {
    cout << 1;
    exit(0);
  }
  if (S.length() > T.length()) {
    return;
  }
  if (T.back() == 'A') {
    string newT = T.substr(0, T.length() - 1);
    DFS(S, newT);
  }
  // 뒤가 A면서 앞이 B인 경우가 있다.
  if (T.front() == 'B') {
    string newT = T.substr(1);
    reverse(newT.begin(), newT.end());
    DFS(S, newT);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string S, T;
  cin >> S >> T;

  DFS(S, T);

  cout << 0;
    
  return 0;
}