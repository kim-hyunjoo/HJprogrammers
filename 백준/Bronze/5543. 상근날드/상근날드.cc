#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int set1 = min(min(a, b), c);
  int d, e;
  cin >> d >> e;
  int set2 = min(d, e);
  cout << set1 + set2 - 50 << endl;
  return 0;
}