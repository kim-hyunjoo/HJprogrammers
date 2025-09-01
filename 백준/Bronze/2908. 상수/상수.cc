#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  int numA = stoi(A);
  int numB = stoi(B);

  cout << max(numA, numB);

  return 0;
}