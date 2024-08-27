#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    int arr[N];
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }

    int dp[N];

    if(N == 1) {
        cout << 0;
        return 0;
    }

    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);

    for(int i=2;i<N;i++) {
        int maxNum = arr[i];
        int minNum = arr[i];
        dp[i] = 0;
        for(int j=i-1;j>0;j--) {
            maxNum = max(maxNum, arr[j]);
            minNum = min(minNum, arr[j]);
            dp[i] = max(dp[i], dp[j-1] + maxNum-minNum);
        }
    }

    cout << dp[N-1];


    return 0;
}
