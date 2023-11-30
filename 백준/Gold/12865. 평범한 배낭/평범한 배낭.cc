#include <stdio.h>

int main() {
    int N, K, W, V, DP[100001] = {}, i = 1, j;
    scanf("%d%d", &N, &K);
    for (; i <= N; i++) { //물건의 개수 N만큼 for문 돌기
        scanf("%d %d", &W, &V);//각 물건마다 무게, 가치 입력
        //j는 k... 최대무게. w는 현재 물건의 무게. 
        for (j = K; j >= W; j--) 
            if (DP[j - W] + V > DP[j]) 
                DP[j] = DP[j - W] + V;
    }
    printf("%d", DP[K]);
}