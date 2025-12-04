#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int A, B;
    cin >> A >> B;

    int temp = 1;
    for (int i = 2; i <= min(A, B); i++) {
      if (A % i == 0 && B % i == 0) {
        temp = i;
      }
    }

    cout << (A * B) / temp << "\n";
  }
  return 0;
}