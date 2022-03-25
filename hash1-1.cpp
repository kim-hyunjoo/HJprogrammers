#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> map;

    for(string s : completion) {
        if(map.find(s) == map.end() ) //만약 해시에서 s를 찾지 못했다면
            map.insert(make_pair(s,1));
        else //해시에 이미 s가 있었다면
            map.at(s)++;
       
    }

    for(string s : participant) {
        if(map.find(s)== map.end()) //만약 해시에서 s를 찾지 못했다면
         {
             answer = s;
             break;
         }
         else { // 만약 해시에서 s를 찾았다면
            map.at(s)--; // 찾았으니까 값 빼주기
            if(map.at(s)<0) { //값이 -가 나오면 그사람이 완주를 못한 사람
                answer = s;
                break;
            }
         }
    }
    
    return answer;

}

int main() {
    vector<string> participant1 = {"leo", "kiki", "eden"};
    vector<string> participant2 = {"marina", "josipa", "nikola", "vinko", "filipa"};
    vector<string> participant3 = {"mislav", "stanko", "mislav", "ana"};
    vector<string> completion1 =  { "eden", "kiki" };
    vector<string> completion2 =  { "josipa", "filipa", "marina", "nikola" };
    vector<string> completion3 =  { "stanko", "ana", "mislav" };

    cout<<solution(participant1, completion1)<<endl;
    cout<<solution(participant2, completion2)<<endl;
    cout<<solution(participant3, completion3)<<endl;
    cout<<"git test"<<endl;
}