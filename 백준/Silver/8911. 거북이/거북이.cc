#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    int test_case;
    cin >> test_case;

    int dir[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};
    for(int t=0; t<test_case; t++) {
        string commands;
        cin >> commands;
        
        int curX = 0, curY = 0, curIdx = 0;
        int dx = dir[curIdx][0];
        int dy = dir[curIdx][1];

        int maxX = 0, maxY = 0, minX = 0, minY = 0;

        for(char command : commands) {
            if(command == 'F') {
                curX += dx;
                curY += dy;
            }
            else if(command == 'B') {
                curX -= dx;
                curY -= dy;
            }
            else if(command == 'L') {
                curIdx = (curIdx + 1) % 4;
                dx = dir[curIdx][0];
                dy = dir[curIdx][1];
            }
            else if(command == 'R') {
                curIdx = (curIdx + 4 - 1) % 4;
                dx = dir[curIdx][0];
                dy = dir[curIdx][1];
            }
            minX = min(curX, minX);
            maxX = max(curX, maxX);
            minY = min(curY, minY);
            maxY = max(curY, maxY);
        }

        cout << abs(maxX - minX) * abs(maxY - minY) << '\n';
    }
    return 0;
}