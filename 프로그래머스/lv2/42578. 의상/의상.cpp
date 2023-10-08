#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
        int answer = 1;
    //unordered_map<string, string> map;
    unordered_map<string, int> clothes_map; // 옷의 종류 - 갯수
    vector<string> clothes_type;
    for(vector<string> v : clothes) {
        //map.insert(make_pair(v[0],v[1])); // key : 옷의 이름 , value : 옷의 종류
        if(clothes_map.find(v[1]) != clothes_map.end()) {
            clothes_map[v[1]]++;
        }
        else {
            clothes_map.insert(make_pair(v[1],2)); //입는경우 + 이 종류의 옷을 아예 입지 않는경우
            clothes_type.push_back(v[1]);
        }
    }

    //경우의 수 따지는 방법
    //일단 맵에 있는 키의 개수 ( 각 하나씩이니까), 
    // 그리고 value의 개수에 따라 달라지는고임... 2개일 때는 ~ value개일때는
    //2개일때는 
    //아니면 종류마다 해시맵응ㄹ 만들어서... 
    int count = clothes_type.size();
    for(int i = 0; i<count; i++) {
        answer *= clothes_map[clothes_type[i]];
        
    }
    return answer-1;
}