#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int C;
    cin >> C;
    cout << C / 25 << " ";
    C = C % 25;
    cout << C / 10 << " ";
    C = C % 10;
    cout << C / 5 << " ";
    C = C % 5;
    cout << C / 1 << "\n";
  }
  return 0;
}