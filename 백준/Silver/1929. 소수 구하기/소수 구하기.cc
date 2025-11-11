#include <iostream>
using namespace std;

bool is_prime(int num) {
  if (num < 2) return false;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return false;
  }
  return true;
}

int main() {
  int M, N;
  cin >> M >> N;
  for (int i = M; i <= N; i++) {
    if (is_prime(i)) {
      cout << i << endl;
    }
  }

  return 0;
}