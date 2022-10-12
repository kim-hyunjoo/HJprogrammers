#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    //전부 대문자로 변경해주는 과정
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    
    vector<string> v1;//str1을 분해해서 넣은 집합
    vector<string> v2;//str2을 분해해서 넣은 집합

    //str1을 분해해서 넣는 과정
    for(int i=0;i<str1.length(); i++) {
        char c1 = str1[i];
        char c2 = str1[i+1];

        //공백, 숫자, 특수문자가 들어간 글자쌍은 무시
        if(isalpha(c1) == 0 || isalpha(c2) == 0) { //만약 알파벳이 아니라면
            continue;//패스...
        }
        string ss = "";
        ss.push_back(c1);
        ss.push_back(c2);
        v1.push_back(ss);
    }

    //str2을 분해해서 넣는 과정
    for(int i=0;i<str2.length(); i++) {
        char c1 = str2[i];
        char c2 = str2[i+1];

        //공백, 숫자, 특수문자가 들어간 글자쌍은 무시
        if(isalpha(c1) == 0 || isalpha(c2) == 0) { //만약 알파벳이 아니라면
            continue;//패스...
        }
        string ss = "";
        ss.push_back(c1);
        ss.push_back(c2);
        v2.push_back(ss);
    }

    //이제 문자열 비교!   
    //비교하기 쉽도록 정렬
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    int sum = v1.size() + v2.size();
    int count = 0;

    //교집합의 개수 = v2에서 찾을 때마다 count+1 해주고 원소 삭제
    for(int i=0;i<v1.size();i++){
        auto it = find(v2.begin(), v2.end(), v1[i]);
        if(it != v2.end()) {//중복원소를 찾았을 경우 카운트 해줌
            count++;
            //해당 원소를 다시 찾지 않도록 삭제 처리
            v2.erase(it);
        }
    }

    //합집합의 개수 = 두 백터의 전체 크기 합 - 교집합의 크기
    sum -= count;

    //합집합이 아예 없어서 공집합일 경우 (0으로 나눌 수 없으니 오류 처리)
    if(sum == 0)
        answer = 65536;
    else{
        float result = ((float)count / (float)sum)* 65536;
        answer = (int)result;
    }
        
    
    return answer;
}

int main() {
    cout << solution("FRANCE", "french")<<endl;
    cout << solution("handshake", "shake hands")<<endl;
    cout << solution("aa1+aa2", "AAAA12")<<endl;
    cout << solution("E=M*C^2", "e=m*c^2")<<endl;
}