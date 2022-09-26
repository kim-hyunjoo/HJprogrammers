//https://programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int count = number.length() - k; //골라야하는 숫자 개수
//1231234 (총 7개, k=3, count = 4)
    
    int idx = 0;
    for(int i=0;i<count;i++) {      
        int max = 0;
        for(int j = idx;j<=k+i;j++) {
            int num = number[j] - '0';
            if(num > max)  {
                max = num;
                idx = j+1;//다음 인덱스 저장
            }
        }
        answer += to_string(max);
    }



    return answer;
}

int main() {
    cout<<solution("1924", 2)<<endl;
    cout<<solution("1231234", 3)<<endl;
    cout<<solution("4177252841", 4)<<endl;
}