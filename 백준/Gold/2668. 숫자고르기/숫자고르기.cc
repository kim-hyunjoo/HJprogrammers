#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr(101);
vector<bool> isVisited(101);
vector<int> answer;

void dfs(int cur, int start) {
  if (isVisited[cur]) {
    if (start == cur) {
      answer.push_back(cur);
    }
    return;
  }

  isVisited[cur] = true;
  dfs(arr[cur], start);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= N; i++) {
    fill(isVisited.begin(), isVisited.end(), false);
    dfs(i, i);
  }

  cout << answer.size() << '\n';
  for (int n : answer) {
    cout << n << '\n';
  }

  return 0;
}
