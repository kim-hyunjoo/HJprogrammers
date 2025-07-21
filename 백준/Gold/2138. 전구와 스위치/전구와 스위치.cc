#include <bits/stdc++.h>
using namespace std;

int N;
string cur, target;

void press(string &cur, int index) {
  cur[index] = cur[index] == '0' ? '1' : '0';
  if (index != 0) {
    cur[index - 1] = cur[index - 1] == '0' ? '1' : '0';
  }
  if (index != N - 1) {
    cur[index + 1] = cur[index + 1] == '0' ? '1' : '0';
  }
}

int run(string cur, bool isPressed) {
  int count = 0;
  if (isPressed) {
    press(cur, 0);
    count++;
  }

  for (int i = 1; i < N; i++) {
    if (cur[i - 1] != target[i - 1]) {
      press(cur, i);
      count++;
    }
  }

  return cur == target ? count : INT_MAX;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  cin >> cur >> target;

  int result1 = run(cur, false);
  int result2 = run(cur, true);

  int answer = min(result1, result2);

  cout << (answer == INT_MAX ? -1 : answer);

  return 0;
}