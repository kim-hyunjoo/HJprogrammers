#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> split(string str, char c) {
  istringstream iss(str);
  string buf_str;
  vector<string> result;
  while (getline(iss, buf_str, c)) {
    result.push_back(buf_str);
  }
  return result;
}

string convert(string str) {
  unordered_map<string, string> map;
  map.insert(make_pair("B#", "U"));
  map.insert(make_pair("C#", "V"));
  map.insert(make_pair("D#", "W"));
  map.insert(make_pair("F#", "X"));
  map.insert(make_pair("G#", "Y"));
  map.insert(make_pair("A#", "G"));

  string convertedStr = "";
  for (int i = 0; i < str.size(); i++) {
    // c랑 그 앞에꺼까지..
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

// 1분에 1개 출력
string solution(string m, vector<string> musicinfos) {
  string answer = "(None)";
  int answerTimes = 0;

  for (int t = 0; t < musicinfos.size(); t++) {
    string str = musicinfos[t];
    vector<string> result = split(str, ',');
    // 제목, 음악정보, 찾을정보
    string title = result[2];
    string musicInfo = convert(result[3]);
    string findInfo = convert(m);
    // 총 시간 구하기
    vector<string> start = split(result[0], ':');
    vector<string> end = split(result[1], ':');
    int times =
        (stoi(end[0]) - stoi(start[0])) * 60 + (stoi(end[1]) - stoi(start[1]));

    //  조건에 맞는 곡보다 시간이 짧으면 어차피 정답이 될 수 없다.
    if (times < answerTimes) continue;
    // 총 시간 동안 들린 노래 정보
    string musicInfoResult = "";

    for (int i = 0; i < times; i++) {
      musicInfoResult += musicInfo[i % musicInfo.size()];
    }

    // 찾는 정보보다 음악이 더 짧으면 어차피 정답이 될 수 없다.
    if (findInfo.size() > musicInfoResult.size()) continue;

    if (musicInfoResult.find(findInfo) != string::npos) {
      if (answerTimes < times) {
        answerTimes = times;
        answer = title;
      }
    }
  }
  return answer;
}