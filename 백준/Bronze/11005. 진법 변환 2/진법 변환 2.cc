#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, B;
  cin >> N >> B;

  string result = "";
  while (N > 0) {
    int remainder = N % B;
    if (remainder < 10) {
      result = to_string(remainder) + result;
    } else {
      result = char(remainder - 10 + 'A') + result;
    }
    N /= B;
  }

  cout << result << "\n";
  return 0;
}