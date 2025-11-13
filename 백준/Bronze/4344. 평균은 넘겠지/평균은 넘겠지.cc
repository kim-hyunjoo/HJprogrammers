#include <bits/stdc++.h>
using namespace std;

int main() {
  int C;
  cin >> C;
  for (int i = 0; i < C; i++) {
    double N;
    cin >> N;
    vector<double> scores(N);
    int sum = 0;
    for (int j = 0; j < N; j++) {
      cin >> scores[j];
      sum += scores[j];
    }
    double average = sum / N;
    int count = 0;
    for (int j = 0; j < N; j++) {
      if (scores[j] > average) {
        count++;
      }
    }
    cout << count / N * 100 << "%" << endl;
  }
  return 0;
}