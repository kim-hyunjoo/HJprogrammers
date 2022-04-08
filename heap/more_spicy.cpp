//https://programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

//섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
void print(priority_queue<int, vector<int>, greater<int>> pq) {
    priority_queue<int, vector<int>, greater<int>> ppp = pq;
    while(!ppp.empty()) {
        cout<<ppp.top();
        ppp.pop();
    }
    cout<<endl;
}
int solution(vector<int> scoville, int K) {
    int answer = 0;
    //우선순위 큐
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i : scoville) {
        pq.push(i);
    }

    int new_k=0, first, second;
    if(pq.top()>K)
        return answer;
    while(pq.top() < K) {
        //만약 pq에 원소가 하나남은 경우 더이상 합칠게 없으므로...
        if(pq.size()==1)
            return -1;
        first = pq.top();
        pq.pop();        
        second = pq.top();
        pq.pop();
        new_k = first + second*2;
        pq.push(new_k);
        answer++;
    }
    return answer;
}

int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12}; 
    cout<< solution(scoville, 7) << endl;
} 