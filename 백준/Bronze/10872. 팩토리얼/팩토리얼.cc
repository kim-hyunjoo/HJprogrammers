#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 1;

  for (int i = N; i > 0; i--) {
    sum *= i;
  }
  cout << sum;
  return 0;
}