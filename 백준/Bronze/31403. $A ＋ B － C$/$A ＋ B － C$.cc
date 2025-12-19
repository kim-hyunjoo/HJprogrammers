#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  cout << A + B - C << endl;

  string str = to_string(A) + to_string(B);

  cout << stoi(str) - C;

  return 0;
}