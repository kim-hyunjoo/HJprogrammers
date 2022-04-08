 //https://programmers.co.kr/learn/courses/30/lessons/42627

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//비교 정렬 구조체!! 오름차순으로 정렬해줌
class compare {
    public:
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1]; 
    }
};

int solution(vector<vector<int>> jobs) { 
    //[작업이 요청되는 시점, 작업의 소요시간]
    int answer = 0;
    //요청 시점 순서대로 정렬
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, compare> pq; //대기하고있는 애들은 여기에 있음.

    int cur_time = 0;//현재 시간
    int sum = 0;
    int index = 0;
    //3,6,9 순으로 pop
    //실행하고 있는 도중에 무언가 들어온것들 중 작업의 소요시간 순서대로 큐에서 정렬시킨 후 모두 빼버려...
    //pq.push(jobs[0]);
    while(!pq.empty() || index < jobs.size()) {
        //현재 작업이 끝날 예정인 시간 cur_time 안에 요청이 들어온 작업이 있다면
        if(index < jobs.size() && cur_time >= jobs[index][0]) {          
            pq.push(jobs[index++]);//pq에 넣는다!
            continue; //그런 작업이 더 있다면 또 넣기
        }
        
        //1. 현재 대기중인 작업이 있는경우 
        if(!pq.empty()){
            cur_time += pq.top()[1]; //이 작업이 끝나는 시점의 시간 저장
            sum += cur_time - pq.top()[0]; //소요시간 = 종료 시간 - 요청시간
            pq.pop();
        }
        
        //2. 현재 대기중인 작업이 없는 경우 다음 작업이 요청 시간으로 time 변경해주기
        else {
            cur_time = jobs[index][0];
        }
    }
    answer = sum/jobs.size();
    return answer;
}

int main() {
    vector<vector<int>> jobs = {{0,3},{1,9},{2,6}}; 
    cout<< solution(jobs)<<endl;
}