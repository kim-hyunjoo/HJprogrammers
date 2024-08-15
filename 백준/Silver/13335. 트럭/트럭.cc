#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    int n, w, L;
    cin >> n >> w >> L;

    int start[n];
    
    for(int i=0;i<n;i++) {
        cin >> start[i];
    }

    int middle[w];
    for(int i=0;i<w;i++) {
        middle[i] = 0;
    }

    int end = 0;
    int answer = 0;
    int curPos = 0;

    while(end < n) {
        int curTruck = start[curPos];
        int outTruck = middle[0];

        if(outTruck != 0) {
            end++;
        }

        for(int i=0;i<w-1;i++) {
            middle[i] = middle[i+1];
        }
        middle[w-1] = 0;

        int curLength = 0;
        int curWeight = 0;
        for(int i=0;i<w;i++) {
            if(middle[i] != 0) {
                curLength++;
            }
            curWeight += middle[i];
        }

        if(curLength < w && curWeight + curTruck <= L) {
            middle[w-1] = curTruck;
            curPos++;
        }

        answer++;
    }

    cout << answer << endl;

    return 0;
}
