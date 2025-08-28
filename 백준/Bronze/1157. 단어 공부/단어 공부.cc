#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;

  vector<int> alpha(26, 0);
    
  for (char c : str) {
    alpha[tolower(c) - 'a']++;
  }

  char max_alpha;
  int max_count = 0;
    
  for (int i = 0; i < 26; i++) {
    if (max_count < alpha[i]) {
      max_count = alpha[i];
      max_alpha = 'A' + i;
    } else if (max_count == alpha[i]) {
      max_alpha = '?';
    }
  }

  cout << max_alpha;

  return 0;
}