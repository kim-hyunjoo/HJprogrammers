#include <bits/stdc++.h>
using namespace std;

long long cut(vector<long long> &trees, int height) {
  long long count = 0;
  for (long long tree : trees) {
    if (tree > height) {
      count += tree - height;
    }
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  long long M;
  cin >> N >> M;

  vector<long long> trees(N);
  for (int i = 0; i < N; i++) {
    cin >> trees[i];
  }

  sort(trees.begin(), trees.end());

  int left = 0;
  int right = trees[N - 1];

  int answer = 0;
  while (left <= right) {
    int mid = (left + right) / 2;

    long long height = cut(trees, mid);
    if (height >= M) {
      answer = max(answer, mid);
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << answer;

  return 0;
}