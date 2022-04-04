//https://programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> queue;
    
    //큐에 각각 걸리는 시간 넣기
    for(int i = 0; i<progresses.size(); i++) {
        int t = (int)ceil((100 - progresses[i])/(double)speeds[i]);
        queue.push(t);
    }

    int maxTime = queue.front();
    int time = 0;
    int count=0;

    while(!queue.empty()) {
        time = queue.front();
        if(maxTime >= time) {
            count++;
            queue.pop();
        }
            
        else {
            answer.push_back(count);
            count = 1;
            maxTime = queue.front();
            queue.pop();
        }
    }

    answer.push_back(count);

    
    return answer;
}

int main() {
    vector<int> progresses1 = {93,30,55};
    vector<int> speeds1 = {1, 30, 5};
    vector<int> progresses2 = {95,90,99,99,80,99};
    vector<int> speeds2 = {1,1,1,1,1,1};
    for(int i : solution(progresses1,speeds1))
        cout<<i<<endl;
    for(int i : solution(progresses2,speeds2))
        cout<<i<<endl;
}