#include <bits/stdc++.h>
using namespace std;

deque<int> split(string str) {
  str = str.substr(1, str.size() - 2);

  stringstream ss(str);
  string buffer;
  deque<int> result;

  while (getline(ss, buffer, ',')) {
    result.push_back(stoi(buffer));
  }

  return result;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    string p, str;
    int n;
    cin >> p >> n >> str;

    deque<int> dq = split(str);
    bool isReverse = false;
    bool isError = false;

    for (char c : p) {
      if (c == 'R') {
        if (!isReverse) {
          isReverse = true;
        } else {
          isReverse = false;
        }
      } else {
        if (dq.size() == 0) {
          isError = true;
          break;
        }
        if (!isReverse) {
          dq.pop_front();
        } else {
          dq.pop_back();
        }
      }
    }

    string result = "";

    if (isError) {
      result = "error";
    } else {
      result += "[";
      if (!isReverse) {
        for (int i = 0; i < dq.size(); i++) {
          if (i != 0) {
            result += ",";
          }
          result += to_string(dq[i]);
        }
      } else {
        for (int i = dq.size() - 1; i >= 0; i--) {
          if (i != dq.size() - 1) {
            result += ",";
          }
          result += to_string(dq[i]);
        }
      }
      result += "]";
    }

    cout << result << '\n';
  }
  return 0;
}