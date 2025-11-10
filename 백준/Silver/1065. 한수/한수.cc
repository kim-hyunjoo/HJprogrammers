#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int count = 0;
  for (int i = 1; i <= N; i++) {
    if (i < 100) {
      count++;
    } else {
      int hundreds = i / 100;
      int tens = (i / 10) % 10;
      int units = i % 10;

      if ((hundreds - tens) == (tens - units)) {
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}