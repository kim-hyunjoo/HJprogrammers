#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    unordered_map<string,int> count_map;
    string buffer = "";
    
    for(char c : s) {
        if(c != '{' && c != '}' && c != ',') {
            buffer += c;
        }
        else if((c == '}' || c == ',') && buffer.length() > 0) {
            count_map[buffer] += 1;
            buffer = "";
        }
    }
    
    vector<pair<string, int>> v(count_map.begin(), count_map.end()); // map을 vector로 변경
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0;i<v.size();i++) {
        answer.push_back(stoi(v[i].first));
    }
    
    return answer;
}