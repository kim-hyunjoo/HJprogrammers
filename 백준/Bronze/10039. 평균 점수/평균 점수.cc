#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> scores;

  for (int i = 0; i < 5; i++) {
    int score;
    cin >> score;
    if (score < 40) score = 40;
    scores.push_back(score);
  }

  int sum = accumulate(scores.begin(), scores.end(), 0);
  cout << sum / 5 << "\n";
  return 0;
}