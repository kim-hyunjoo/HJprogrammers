#include <iostream>
using namespace std;

int main() {
  int N;
  string str;
  cin >> N >> str;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int num = str[i] - '0';
    sum += num;
  }
  cout << sum;
  return 0;
}