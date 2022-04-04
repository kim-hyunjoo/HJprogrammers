//https://programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    vector<int> result;
    queue<int> queue; //큐에 인덱스로 저장해야할듯 ㅠㅠ..
    unordered_map<int, int> map;
    
    for (int i = 0; i < priorities.size(); i++) {
        queue.push(i);
        map.insert(make_pair(i, priorities.at(i))); //인덱스 - 우선순위값
    }
    
    sort(priorities.begin(), priorities.end(),greater<>());

    while (!queue.empty()) {
        //1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
        int j = queue.front();
        queue.pop();
        //2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
        if (priorities[0] > map[j]) {
            queue.push(j);
        }
        //3. 그렇지 않으면 J를 인쇄합니다.
        else { //p_list에서도 제거해주기
            priorities.erase(priorities.begin() + 0);
            result.push_back(j);
        }
    }

    for (int r : result) {
        if (r == location)
            break;
        answer++;
    }
    return answer;
}

int main() {
    vector<int> priorities1 = { 2, 1, 3, 2 };
    cout << solution(priorities1, 2) << endl;
    vector<int> priorities2 = { 1,1,9,1,1,1 };
    cout << solution(priorities2, 0) << endl;
}