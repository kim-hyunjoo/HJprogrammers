//https://programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n-lost.size(); // 일단 잃어버린애들 빼고 나머지는 옷 있음

    //편하게 검색하려고 만든 map들
    unordered_map<int,int> lost_map; //lost map
    unordered_map<int,int> reserve_map; //reserve map
    unordered_map<int,int> lent; //이미빌려준애들

    //정렬해놓기
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for(int i : lost) {
        lost_map.emplace(i,1);
    }

    for(int i : reserve) {
        if(lost_map.find(i) != lost_map.end()) {//만약 스스로 잃어버렸다면 스스로에게 여분을 줌 
            answer++;
            lent.emplace(i,1); //이미 빌려준애들에 추가
            lost.erase(remove(lost.begin(), lost.end(), i), lost.end()); //lost에서도 지워줘야함
            continue;
        }
        reserve_map.emplace(i,1);
    }

    for(int i =0;i<lost.size();i++) {
        int lost_stu = lost[i];
        for(int j = lost_stu-1 ; j <=lost_stu+1;j++) {
            //j가 reserve에 존재한다면 빌려주기 가능. answer ++;
            //이미 빌려준적 있으면 안됨
            if(lent.find(j) == lent.end() && reserve_map.find(j)!=reserve_map.end()) {
                answer++;
                lent.emplace(j,1);
                break;
            }
                
        }
    }
    return answer;
}

int main() {
    cout << solution(5,{2,4},{1,3,5}) <<endl;
    cout << solution(5,{2,4},{3}) <<endl;
    cout << solution(3,{3},{1}) <<endl;
    cout << solution(5,{1,2,4},{2,4,5}) <<endl;
    cout << solution(5,{1,2,4},{2,3,4,5}) <<endl;
}