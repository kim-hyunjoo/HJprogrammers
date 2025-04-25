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

  unordered_map<int, int> map;

  for (int i = 0; i < topping.size(); i++) {
    map[topping[i]]++;
  }

  int min_topping = ceil((double)map.size() / 2.0);

  unordered_map<int, int> left_map;
  unordered_map<int, int> right_map;

  for (int i = 0; i < min_topping; i++) {
    left_map[topping[i]]++;
  }

  for (int i = min_topping; i < topping.size(); i++) {
    right_map[topping[i]]++;
  }

  for (int i = min_topping; i <= topping.size() - min_topping; i++) {
    if (left_map.size() == right_map.size()) {
      answer++;
    }
    int temp = topping[i];

    left_map[temp]++;
    if (right_map[temp] > 0) {
      right_map[temp]--;
    }
    if (right_map[temp] == 0) {
      right_map.erase(temp);
    }
  }
  return answer;
}
