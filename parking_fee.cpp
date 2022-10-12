//https://school.programmers.co.kr/learn/courses/30/lessons/92341?language=cpp

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    //출차된 내역이 없으면 23:59에 출차되었다고 간주함.
    
    //차번호 저장하는 벡터
    vector<string> car;
    //차번호랑 in, out 시간을 저장해주면 좋을듯? 각자 IN 해시테이블, OUT 해시테이블 이렇게 두개!
    

    return answer;
}

int main() {
    vector<int>fees1 = {180, 5000, 10, 600};
    vector<int>fees2 = {120, 0, 60, 591};
    vector<int>fees3 = {1, 461, 1, 10};

    vector<string> records1 = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", 
    "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", 
    "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    vector<string> records2 = {"16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT",
    "18:00 0202 OUT","23:58 3961 IN"};
    vector<string> records3 = {"00:00 1234 IN"};

    vector<int> result1 = solution(fees1, records1);
    vector<int> result2 = solution(fees2, records2);
    vector<int> result3 = solution(fees3, records3);

    for(int i : result1) {
        cout << i <<endl;
    }
    for(int i : result2) {
        cout << i <<endl;
    }
    for(int i : result3) {
        cout << i <<endl;
    }
}