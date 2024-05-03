#include <iostream>
#include <vector>
using namespace std;

int N;
int map[128][128];
int totalWhite = 0;
int totalBlue = 0;

void dfs(int startR, int endR, int startC, int endC, int N) {
    int color = map[startR][startC];
    for(int r=startR; r<endR; r++) {
        for(int c=startC; c<endC; c++) {
            if(map[r][c] != color && N > 1) {
                dfs(startR, startR + N/2, startC, startC + N/2, N/2);
                dfs(startR + N/2, endR, startC, startC + N/2, N/2);
                dfs(startR, startR + N/2, startC + N/2, endC, N/2);
                dfs(startR + N/2, endR, startC + N/2, endC, N/2);
                return;
            }
        }
    }

    color == 0 ? totalWhite++ : totalBlue++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   // freopen("input.txt", "r", stdin);

    cin >> N;

    for(int r=0;r<N;r++) {
        for(int c=0;c<N;c++) {
            cin >> map[r][c];
        }
    }

    dfs(0,N,0,N,N);
    cout << totalWhite << '\n' << totalBlue;

    return 0;
}