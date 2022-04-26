//https://programmers.co.kr/learn/courses/30/lessons/42628

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> max; // 최댓값 우선
    priority_queue<int, vector<int>, greater<int>> min; // 최솟값 우선
    
    //push,pop 때마다 카운트
    int push_count=0, pop_count = 0;

    for(string op : operations) {

        //만약 큐가 비어있을 경우 큐 초기화
        if(push_count == pop_count) {
            max = priority_queue<int>();
            min = priority_queue<int, vector<int>, greater<int>>();
        }

        //문자열 분리
        istringstream ss(op);
        string stringBuffer;
        vector<string> x;
        while (getline(ss, stringBuffer, ' ')){
            x.push_back(stringBuffer);
        }

        //삽입연산       
        if(x[0] == "I") {
            max.emplace(stoi(x[1]));
            min.emplace(stoi(x[1]));
            push_count++;
        }
        
        //최댓값 삭제
        else if (op == "D 1") {
            //큐가 비어있을 경우 패스
            if(push_count == pop_count)
                continue;
            max.pop();
            pop_count++;
        }

        //최솟값 삭제
        else if (op == "D -1") {
            //큐가 비어있을 경우 패스
            if(push_count == pop_count)
                continue;
            min.pop();
            pop_count++;
        }
    }

    //큐가 비어있을 경우 [0,0] 리턴
    if(push_count == pop_count) {
        answer.push_back(0);
        answer.push_back(0);
    }

    //최댓값, 최솟값 리턴
    else {
        answer.push_back(max.top());
        answer.push_back(min.top());
    }
    
    return answer;
}

int main() {
    vector<string> operations1 = {"I 16","D 1"};
    vector<string> operations2 = {"I 7","I 5","I -5","D -1"};
    vector<string> operations3 = {"I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6"};
    for(int i : solution(operations1)) {
        cout << i <<endl;
    }
    for(int i : solution(operations2)) {
        cout << i <<endl;
    }
    for(int i : solution(operations3)) {
        cout << i <<endl;
    }
}