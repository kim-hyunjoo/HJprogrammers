#include <string>
using namespace std;

bool isValid(int x, int y) {
    if(x < 0 || x > 10 || y < 0 || y > 10) {
        return false;
    }
    return true;
}

int solution(string dirs) {
    int answer = 0;
    
    int dx[4] = {0,1,0,-1}; //U R D L
    int dy[4] = {1,0,-1,0};
    
    int curX = 5;
    int curY = 5;
    
    bool isVisited[11][11][4];
    fill_n(&isVisited[0][0][0], 11*11*4, false);
    
    for(char dirChar : dirs) {
        int dir = 0;
        switch(dirChar) {
            case 'D':
                dir = 2;
                break;
            case 'L':
                dir = 3;
                break;
            case 'R':
                dir = 1;
                break;
        }
        int reverseDir = (dir+2)%4;
        int nextX = curX + dx[dir];
        int nextY = curY + dy[dir];
        
        if(!isValid(nextX,nextY)) {
            continue;
        }
        
        if(!isVisited[curX][curY][dir] && !isVisited[nextX][nextY][reverseDir]) {
            isVisited[curX][curY][dir] = true;
            isVisited[nextX][nextY][reverseDir] = true;
            answer++;
        }
        
        curX = nextX;
        curY = nextY;
        
        
    }
    
    return answer;
}