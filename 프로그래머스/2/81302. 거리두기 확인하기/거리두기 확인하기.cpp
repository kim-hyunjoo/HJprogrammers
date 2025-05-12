#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    // 총 12방향 탐색
    int dr[12] = {0,0,1,-1,-1,1,-1,1,0,0,-2,2};
    int dc[12] = {1,-1,0,0,-1,-1,1,1,-2,2,0,0};
    
    for(auto place : places) {
        bool flag = true;
        for(int r=0;r<5;r++) {
            for(int c=0;c<5;c++) {
                if(place[r][c] == 'P') {
                    for(int i=0;i<12;i++) {
                        int nr = r+dr[i];
                        int nc = c+dc[i];
                        if(nr < 0 || nc < 0 || nr >= 5 || nc >= 5) continue;
                        // 탐색 범위에 또다른 P가 있다면
                        if(place[nr][nc] == 'P') {
                            // 상하좌우에 있다면 실패
                            if(i < 4) {
                                flag = false;
                            }
                            // 대각선에 있다면
                            else if(i >= 4 && i < 8) {
                                if(place[nr][c] == 'O' || place[r][nc] == 'O') {
                                    flag = false;  
                                }
                            }
                            // 2칸 직선거리에 있다면
                            else {
                                if(place[(nr+r)/2][(nc+c)/2] == 'O'){
                                    flag = false;
                                }
                            }
                        }
                    }
                }
            }
        }
        answer.push_back(flag ? 1 : 0);    
    }
    
    return answer;
}