#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    // 시간대 별 서버의 수
    vector<int> server_count(48);
    
    for(int i=0;i<players.size();i++) {
        int player_count = players[i];
        // 현재 필요한 서버의 수
        int cur_server_count = player_count / m;
        
        // 만약 서버를 증설해야 한다면?
        if(server_count[i] < cur_server_count) {
            // k번 만큼 서버 증설
            int new_server_count = cur_server_count - server_count[i];
            for(int j=i;j<i+k;j++) {
                server_count[j] += new_server_count;
            }
            answer += new_server_count;
        }
        
    }
    return answer;
}