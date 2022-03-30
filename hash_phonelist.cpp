//https://programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> map;

    //해시 맵 생성
    for(string s : phone_book) {
        map.insert(make_pair(s, 1));
    }

    //해시 탐색
    //번호 하나당 substr을 그 단어의 길이만큼 for문 돌면서 map에서 찾음
    //만약 map에 존재한다면 false
    for(string s : phone_book) {
        for(int i=1;i<s.length();i++) {
            //만약 있을 경우
            if(map.find(s.substr(0,i)) != map.end()) {
                answer = false;
            }
                
        }
    }


    return answer;
}

int main() {
    vector<string> phone_book1 = {"119", "97674223", "1195524421"};
    vector<string> phone_book2 = {"123","456","789"};
    vector<string> phone_book3 = {"12","123","1235","567","88"};

    bool result = solution(phone_book1);
    if(result == true)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    result = solution(phone_book2);
    if(result == true)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    result = solution(phone_book3);
    if(result == true)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}