#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> answers;

int add(string str) {
  int sum = 0;
  int temp = 0;
  char sign = '+';

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '+' || str[i] == '-') {
      if (sign == '+') {
        sum += temp;
      } else {
        sum -= temp;
      }
      temp = 0;
      sign = str[i];
    } else {
      temp = temp * 10 + (str[i] - '0');
    }
  }

  if (sign == '+') {
    sum += temp;
  } else {
    sum -= temp;
  }

  return sum;
}

void dfs(int num, string str) {
  if (num == N) {
    string sumStr = str;
    sumStr.erase(remove(sumStr.begin(), sumStr.end(), ' '), sumStr.end());
    int sum = add(sumStr);

    if (sum == 0) {
      answers.push_back(str);
    }
    return;
  }

  dfs(num + 1, str + '+' + to_string(num + 1));
  dfs(num + 1, str + '-' + to_string(num + 1));
  dfs(num + 1, str + ' ' + to_string(num + 1));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    if (t != 0) {
      cout << '\n';
    }

    cin >> N;
    answers.clear();
    dfs(1, "1");

    sort(answers.begin(), answers.end());

    for (string answer : answers) {
      cout << answer << '\n';
    }
  }
  return 0;
}