#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  getline(cin, str);

  int count = 0;
  bool inWord = false;

  for (char c : str) {
    if (c != ' ' && !inWord) {
      inWord = true;
      count++;
    } else if (c == ' ') {
      inWord = false;
    }
  }

  cout << count;
  return 0;
}
