#include <iostream>
using namespace std;

bool isPrime(int num) {
  if (num < 2) return false;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return false;
  }
  return true;
}
int main() {
  int M, N;
  cin >> M >> N;

  int sum = 0;
  int firstPrime = -1;
  for (int i = M; i <= N; i++) {
    if (isPrime(i)) {
      sum += i;
      if (firstPrime == -1) {
        firstPrime = i;
      }
    }
  }

  if (sum == 0) {
    cout << -1 << "\n";
  } else {
    cout << sum << "\n" << firstPrime << "\n";
  }

  return 0;
}