#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;

    int count = 0;
    int sum = 0;
    for (char c : str) {
      if (c == 'O') {
        count++;
        sum += count;
      } else {
        count = 0;
      }
    }

    cout << sum << '\n';
  }
  return 0;
}