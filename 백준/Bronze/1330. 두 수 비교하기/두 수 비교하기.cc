#include <iostream>
using namespace std;

int main() {
  // 코드 작성
  int A, B;
  cin >> A >> B;

  if (A > B) {
    cout << '>';
  } else if (A < B) {
    cout << '<';
  } else {
    cout << "==";
  }
  return 0;
}