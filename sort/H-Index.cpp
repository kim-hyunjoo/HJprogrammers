//https://programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    //내림차순 정렬
    sort(citations.begin(), citations.end(), greater<>());

    //h시작은 가장 큰 값
    int h = citations[0];
    int count = 0;

    for(int i=h;i>0;i--){
        for(int c : citations) {
            if(c>=h) { //h번이상 인용된 논문 세기
                count++;
            }  
            else
                break;      
        }
        //h번 이상 인용된 논문이 h편 이상일 경우 최댓값은 h
        if(count>=h) {
            answer = h;
            break;
        }
        h--;
        count=0;
    }
    

    return answer;
}

int main() {
    vector<int> citations = {0,1,2,3,3,3,3,3,3,4,10,20,30,40};
    cout<<solution(citations)<<endl;
}