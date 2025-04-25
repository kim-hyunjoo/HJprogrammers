#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
  int answer = 0;

  if (topping.size() == 1) {
    return 0;
  }

  unordered_map<int, int> left_map;
  unordered_map<int, int> right_map;

  for (int i = 0; i < topping.size(); i++) {
    right_map[topping[i]]++;
  }

  for (int i = 0; i < topping.size(); i++) {
    left_map[topping[i]]++;
    right_map[topping[i]]--;
    if (right_map[topping[i]] == 0) {
      right_map.erase(topping[i]);
    }
    if (left_map.size() == right_map.size()) {
      answer++;
    }
  }
  return answer;
}

