#include <bits/stdc++.h>

using namespace std;

string reverseStr(string str) {
    string newStr = "";
    for(char c : str) {
        if(c == '(') {
            newStr += ')';
        }
        else {
            newStr += '(';
        }
    }
    return newStr;
}

bool check(string u) {
    int left = 1;
    int right = 0;
    if(u[0]==')') return false;
    for(int i=1;i<u.length();i++) {
        if(u[i]=='(') {
            left++;
        }
        else {
            right++;
        }
        if(left < right) {
            return false;
        }
    }
    return true;
}

string dfs(string w) {
    // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
    if(w == "") {
        return "";
    }    
    string u = "";
    string v = "";
    int left = 0;
    int right = 0;
    // 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
    for (int i=0;i<w.length();i++) {
        if(w[i] == '(') {
            left++;   
        }
        else {
            right++;
        }
        u += w[i];
        
        if(left == right) {
            v = w.substr(i+1);
            break;
        }
    }
    
    // 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
    if(check(u)) {
        return u+dfs(v);
    }
    // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
    else {
        // 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
        string str = "(";
        // 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
        str += dfs(v);
        // 4-3. ')'를 다시 붙입니다. 
        str += ")";
        //   4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
        u = u.substr(1, u.length()-2);
        str += reverseStr(u);
        return str;
    }  
}

string solution(string p) {
    string answer = dfs(p);
    
    return answer;
}

