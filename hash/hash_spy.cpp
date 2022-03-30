//https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> clothes_map; // <옷의 종류 , 갯수>
    vector<string> clothes_type; //옷의 종류를 저장하는 배열
    for(vector<string> v : clothes) {
        if(clothes_map.find(v[1]) != clothes_map.end()) { //만약 map에 이 옷종류가 있다면 개수 추가
            clothes_map[v[1]]++;
        }
        else { // 만약 map에 이 옷 종류가 없다면 옷 종류 추가해줌
            clothes_map.insert(make_pair(v[1],2)); //입는경우 + 이 종류의 옷을 아예 입지 않는경우 = 2
            clothes_type.push_back(v[1]);
        }
    }

    //옷의 개수 조합 공식
    //각 옷 종류의 개수+1 (안 입는 경우 포함) 끼리 곱해준 다음 마지막에 -1 (아무것도 안입는 경우 제외)
    int count = clothes_type.size();
    for(int i = 0; i<count; i++) {
        answer *= clothes_map[clothes_type[i]];

    }
    return answer-1;
}

int main() {
    vector<vector<string>> clothes1 = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    vector<vector<string>> clothes2 = {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}};
    cout << "result : " << solution(clothes1) << solution(clothes2) << endl;
}