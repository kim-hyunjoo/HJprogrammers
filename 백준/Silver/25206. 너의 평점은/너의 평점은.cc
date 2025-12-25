#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_map<string, double> m;
  m["A+"] = 4.5;
  m["A0"] = 4.0;
  m["B+"] = 3.5;
  m["B0"] = 3.0;
  m["C+"] = 2.5;
  m["C0"] = 2.0;
  m["D+"] = 1.5;
  m["D0"] = 1.0;
  m["F"] = 0.0;
  double total_score = 0;
  double total_credit = 0;
  for (int i = 0; i < 20; i++) {
    string major, grade;
    double credit;
    cin >> major >> credit >> grade;
    if (grade != "P") {
      total_score += credit * m[grade];
      total_credit += credit;
    }
  }

  cout << fixed;
  cout.precision(6);
  cout << total_score / total_credit << "\n";
  return 0;
}