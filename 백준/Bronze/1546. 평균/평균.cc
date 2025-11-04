#include <bits/stdc++.h>
using namespace std;

int main() {
  double N;
  cin >> N;
  vector<double> scores(N);
  for (int i = 0; i < N; i++) {
    cin >> scores[i];
  }

  double M = *max_element(scores.begin(), scores.end());

  for (int i = 0; i < N; i++) {
    double s = scores[i];
    double new_score = s / M * 100.0;
    scores[i] = new_score;
  }

  double sum = 0.0;
  for (int i = 0; i < N; i++) {
    sum += scores[i];
  }
  double average = sum / N;
  cout << average << "\n";
  return 0;
}