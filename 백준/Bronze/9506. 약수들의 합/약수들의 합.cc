#include <bits/stdc++.h>
using namespace std;

vector<int> getDivisors(int n) {
  vector<int> divisors;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (i != n / i) {
        divisors.push_back(n / i);
      }
    }
  }

  sort(divisors.begin(), divisors.end());

  return divisors;
}

bool isPerfect(int n) {
  vector<int> divisors = getDivisors(n);

  int sum = 0;
  for (int d : divisors) {
    if (d != n) {
      sum += d;
    }
  }

  return sum == n;
}

int main() {
  while (true) {
    int num;
    cin >> num;
    if (num == -1) {
      break;
    }
    if (isPerfect(num)) {
      cout << num << " = ";
      vector<int> divisors = getDivisors(num);
      cout << divisors[0];
      for (int j = 1; j < divisors.size() - 1; j++) {
        cout << " + " << divisors[j];
      }
      cout << endl;
    } else {
      cout << num << " is NOT perfect." << endl;
    }
  }
  return 0;
}