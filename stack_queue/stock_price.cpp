//https://programmers.co.kr/learn/courses/30/lessons/42584

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size); //벡터의 크기를 처음에 지정해줘야 배열처럼 사용 가능
    stack<pair<int, int>> s;

    for(int i=0;i<size; i++) {      
        //만약에 스택 내부의 주식 가격이 현재 가격보다 높을경우 떨어진거니까 
        //현재시점 i 에서 그당시시점 s.top().first을 빼준다(인덱스끼리 빼주면 버틴 시간이 됨)
        while(!s.empty() && s.top().second > prices[i]) {
            answer[s.top().first] = i-s.top().first;
            s.pop();
        }
        s.emplace(i, prices[i]);
    }
    while(!s.empty()) {
        //끝까지 버틴애들
        answer[s.top().first] = size- s.top().first-1;
        s.pop();
    }
    
    
    return answer;
}

int main() {
    vector<int> prices = {1, 2, 3, 2, 3};
    vector<int> result = solution(prices);
    for(int i : result) {
        cout<<i<<endl;
    }
}