#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string,int> dict;

    // A~Z 사전 입력
    for(int i=1;i<=26;i++) {
        char c = i+64;
        string s(1, c);
        dict.insert({s,i});
    }
    
    int i=0;
    string w(1, msg[0]);
    while(i < msg.size()) {
        char c = msg[i+1];
        string wc = w+c;
        //만약 사전에 존재하면 다음 글자 추가
        if(dict.count(wc) == 1) {
            w= wc;
        }
        //사전에 존재하지 않으면 사전에 추가하고 출력
        else {
            answer.push_back(dict[w]);
            dict.insert({wc, dict.size()+1});
            w="";
            w+=c;
        }
        i++;
    }
    
    return answer;
}