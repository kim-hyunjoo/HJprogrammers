#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, char delimiter) {
  istringstream iss(str);
  string buffer;

  vector<string> result;

  while (getline(iss, buffer, delimiter)) {
    result.push_back(buffer);
  }

  return result;
}

void printStr(string str, int i) {
  cout << str.substr(0, i);
  cout << '[' << str[i] << ']';
  cout << str.substr(i + 1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  cin.ignore();  // 개행 문자 삭제

  unordered_map<char, int> map;
  string option;

  for (int t = 0; t < N; t++) {
    getline(cin, option);  // 한 줄 전체 입력

    vector<string> splitOption = split(option, ' ');
    bool flag = false;

    // 1. 단어 첫글자만 탐색
    for (int i = 0; i < splitOption.size(); i++) {
      char c = splitOption[i][0];
      // 이미 사용한 적 있으면 패스
      if (map.count(toupper(c))) {
        continue;
      }
      // 없으면 사용 표시하고
      map[toupper(c)]++;

      // 출력
      int idx = 0;
      for (int j = 0; j < i; j++) {
        idx += splitOption[j].length() + 1;
      }
      printStr(option, idx);

      flag = true;
      break;
    }
    if (flag) continue;

    // 2. 없을 경우 차례대로 탐색
    for (int i = 0; i < option.length(); i++) {
      char c = option[i];
      // 공백의 경우 패스
      if (c == ' ') {
        continue;
      }
      if (map.count(toupper(c))) {
        continue;
      }

      // 없으면 사용 표시하고
      map[toupper(c)]++;
      // 출력
      printStr(option, i);

      flag = true;
      break;
    }
    if (flag) continue;

    // 3. 진짜 없을 경우 그냥 출력
    cout << option << '\n';
  }

  return 0;
}