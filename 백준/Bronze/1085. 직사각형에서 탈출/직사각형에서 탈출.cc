#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, w, h;
  cin >> x >> y >> w >> h;
  int min1 = min(x, w - x);
  int min2 = min(y, h - y);
  cout << min(min1, min2) << endl;
  return 0;
}