#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    cout << str.front() << str.back() << '\n';
  }
  return 0;
}