#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0,0 };
    unordered_map<string, int> dict;
    dict[words[0]] = 1;

    for(int i=1; i<words.size(); i++) {
        if(!dict[words[i]] && words[i-1].back() == words[i].front()) {
            dict[words[i]] = 1;
        }   
        else {
            answer = { i % n + 1, i / n + 1 };
            break;
        }
    }

    return answer;
}