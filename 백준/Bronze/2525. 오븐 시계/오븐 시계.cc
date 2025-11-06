#include <iostream>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int total = A * 60 + B + C;
  int newA = (total / 60) % 24;
  int newB = total % 60;
  cout << newA << " " << newB << endl;
  return 0;
}