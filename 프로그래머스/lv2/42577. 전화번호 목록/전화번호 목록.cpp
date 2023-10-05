#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> map;
    for(string s : phone_book) {
        map.insert(make_pair(s, 1));
    }

    for(string s : phone_book) {
        for(int i=1;i<s.length();i++) {
            if(map.find(s.substr(0,i)) != map.end()) {
                answer = false;
            }
              
        }
    }
    return answer;
}