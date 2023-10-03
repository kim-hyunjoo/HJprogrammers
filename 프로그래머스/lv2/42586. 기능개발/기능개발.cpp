#include <string>
#include <vector>
#include <queue>
#include <cmath>

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
    while(!queue.empty()) { //큐에는 각각 7,3,9 //// 5,10,1,1,20,1
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