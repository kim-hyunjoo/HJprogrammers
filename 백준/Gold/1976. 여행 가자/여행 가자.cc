#include <bits/stdc++.h>
using namespace std;

int N, M;
int graph[201][201];
bool visited[201];

void dfs(int start) {
  visited[start] = true;
  for (int i = 1; i <= N; i++) {
    if (graph[start][i] && !visited[i]) {
      dfs(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> graph[i][j];
    }
  }

  vector<int> plan(M);
  for (int i = 0; i < M; i++) {
    cin >> plan[i];
  }

  dfs(plan[0]);

  int flag = true;
  for (int city : plan) {
    if (!visited[city]) {
      flag = false;
      break;
    }
  }

  cout << (flag ? "YES" : "NO");

  return 0;
}