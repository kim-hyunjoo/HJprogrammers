#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    string str;
    cin >> n >> str;
    for (char c : str) {
      for (int j = 0; j < n; j++) {
        cout << c;
      }
    }
    cout << '\n';
  }
  return 0;
}