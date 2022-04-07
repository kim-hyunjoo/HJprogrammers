#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int,int>> queue; // 트럭이 처음 들어온 시간 - 트럭 무게

    int time = 0; //총 걸린 시간

    int bridge_weight = 0; //현재 다리 위의 무게

    for(int i=0;i<truck_weights.size(); i++) {      
        //만약 다리위의 트럭중 나가야하는게 있다면 나가기
        if(time == queue.front().first + bridge_length) {
            bridge_weight -= queue.front().second; //다리 무게에서 빼준 뒤
            queue.pop(); //빠져나오기        
        }
        //만약 다리 무게 초과면 더 올리지말고 기존의 트럭만 하나씩 앞으로 옮기기
        if(bridge_weight + truck_weights[i] > weight) {
            time++;
            i--;
            continue;            
        }          
        //무게를 초과하지 않는다면 트럭 추가
        queue.emplace(time, truck_weights[i]);
        bridge_weight += truck_weights[i];
        time++; 
    }
    //마지막에 들어간 차까지 빠져나가고 + 1
    answer = queue.back().first + bridge_length + 1;
    return answer;
}

int main() {
    vector<int> v1 = {7,4,5,6};
    vector<int> v2 = {10};
    vector<int> v3 = {10,10,10,10,10,10,10,10,10,10};
    cout<<solution(2,10, v1)<<endl;
    cout<<solution(100,100,v2)<<endl;
    cout<<solution(100,100,v3)<<endl;
}