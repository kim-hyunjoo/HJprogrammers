#include <bits/stdc++.h>
using namespace std;

int N, K, P, X;
int answer = 0;

string segment[10] = {"1111110", "0110000", "1101101", "1111001", "0110011",
                      "1011011", "1011111", "1110000", "1111111", "1111011"};

// 두 숫자 사이의 반전해야 하는 LED 개수
int getDiff(char a, char b) {
  int count = 0;
  for (int i = 0; i < 7; i++) {
    if (segment[a - '0'][i] != segment[b - '0'][i]) count++;
  }
  return count;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K >> P >> X;

  string str = to_string(X);
  while (str.length() < K) str = "0" + str;

  for (int i = 1; i <= N; i++) {
    if (i == X) continue;

    string target = to_string(i);
    while (target.length() < K) target = "0" + target;

    int count = 0;
    for (int j = 0; j < K; j++) {
      count += getDiff(str[j], target[j]);
    }

    if (count <= P) answer++;
  }

  cout << answer;
}