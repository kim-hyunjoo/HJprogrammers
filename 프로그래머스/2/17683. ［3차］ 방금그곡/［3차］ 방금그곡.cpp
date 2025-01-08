#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> split(string str, char separator) {
  istringstream iss(str);
  string bufStr;
  vector<string> result;
  while (getline(iss, bufStr, separator)) {
    result.push_back(bufStr);
  }
  return result;
}

string convert(string str) {
  string convertedStr = "";
  unordered_map<string, string> map;

  map.insert(make_pair("B#", "U"));
  map.insert(make_pair("C#", "V"));
  map.insert(make_pair("D#", "W"));
  map.insert(make_pair("F#", "X"));
  map.insert(make_pair("G#", "Y"));
  map.insert(make_pair("A#", "Z"));

  for (int i = 0; i < str.size(); i++) {
    string ss = "";
    ss += str[i];
    ss += str[i + 1];
    if (map.find(ss) != map.end()) {
      convertedStr += map[ss];
      i++;
    } else {
      convertedStr += str[i];
    }
  }

  return convertedStr;
}

string solution(string m, vector<string> musicinfos) {
  string answer = "(None)";
  int answerTimes = 0;

  for (auto musicinfo : musicinfos) {
    vector<string> result = split(musicinfo, ',');
    // 제목, 음악정보, 찾을정보
    string title = result[2];
    string music = convert(result[3]);
    string findMusic = convert(m);
    // 총 시간 구하기
    vector<string> start = split(result[0], ':');
    vector<string> end = split(result[1], ':');
    int times =
        (stoi(end[0]) - stoi(start[0])) * 60 + (stoi(end[1]) - stoi(start[1]));

    //  조건에 맞는 곡보다 시간이 짧으면 어차피 정답이 될 수 없다.
    if (times < answerTimes) continue;

    // 총 시간 동안 들린 노래 정보
    string musicFull = "";

    for (int i = 0; i < times; i++) {
      musicFull += music[i % music.size()];
    }

    if (musicFull.find(findMusic) != string::npos) {
      if (answerTimes < times) {
        answerTimes = times;
        answer = title;
      }
    }
  }
  return answer;
}