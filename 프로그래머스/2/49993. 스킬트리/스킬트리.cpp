#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
//순서가 필요함!!! 순서가 보장.. 그러면 흠 . . . 
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, bool> isLearned;
    unordered_map<char, char> prevSkill;
    
    for(int i=0;i<skill.length();i++) {
        isLearned.insert({skill[i], false});
        if(i==0) continue;
        prevSkill.insert({skill[i], skill[i-1]});
    }
    
    for(string skill_tree : skill_trees) {
        bool isPossible = true;
        cout << skill_tree << endl;
        for(char c: skill_tree) {
            //만약 선행 되어야하는 스킬이 존재한다면
            if(isLearned.count(c) == 1) {
                // 첫번째 스킬이라면
                if(c == skill[0]) {
                    isLearned[c] = true;
                    continue;
                }
                //선행 스킬을 배웠다면 사용
                if(isLearned[prevSkill[c]]) {
                    isLearned[c] = true;
                }
                //선행 스킬 안배운거면 불가능한 스킬트리
                else {
                    isPossible = false;
                    break;
                }
            }
        }
        if(isPossible) answer++;
        
        //isLearned clean up
        isLearned.clear();
        for(int i=0;i<skill.length();i++) {
            isLearned.insert({skill[i], false});
        }
    }
    
    return answer;
}