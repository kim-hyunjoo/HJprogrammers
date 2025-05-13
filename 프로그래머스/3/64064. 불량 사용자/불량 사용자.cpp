#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> mapping_ids; // 매핑된 응모자 아이디
vector<vector<string>> cases; // 경우의 수
int answer = 0;

void dfs(int depth, vector<string>& curV) {
    if(depth == mapping_ids.size()) {
        answer++;
        cases.push_back(curV);
        return;
    }
    
    for(int i=0;i<mapping_ids[depth].size();i++) {
        if(find(curV.begin(), curV.end(), mapping_ids[depth][i]) != curV.end()) continue;
        curV.push_back(mapping_ids[depth][i]);
        dfs(depth+1, curV);
        curV.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {  
    // 매핑된 아이디 찾기
    for (string b_id : banned_id) {
        vector<string> v;
        for(string u_id : user_id) {
            if(b_id.length()!= u_id.length()) continue;
            bool flag = true;
            for(int i=0;i<b_id.length();i++) {
                if(b_id[i] == '*') continue;
                if(b_id[i] != u_id[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                v.push_back(u_id);
            }
        }
        mapping_ids.push_back(v);
    }
    
    // 경우의 수 탐색
    vector<string> curV;
    dfs(0, curV);
      
    // 중복 제거를 위한 정렬
    for(int i=0;i<cases.size();i++) {
        sort(cases[i].begin(), cases[i].end());
    }
    sort(cases.begin(),cases.end());
    
    // 중복된 원소를 가진 조합은 경우의 수 제거
    for(int i=0;i<cases.size()-1;i++) {
        if(is_permutation(cases[i].begin(),cases[i].end(),cases[i+1].begin())) {
            answer--;
        }
    }
    
    return answer;
}