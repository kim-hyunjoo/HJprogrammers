#include <iostream>
using namespace std;

int main() {
  int max_value = 0;
  int index = 0;
  for (int i = 1; i <= 9; i++) {
    int n;
    cin >> n;
    if (n > max_value) {
      max_value = n;
      index = i;
    }
  }
  cout << max_value << '\n' << index;
  return 0;
}