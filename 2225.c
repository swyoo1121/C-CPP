#include <stdio.h>
#define DIVISOR 1000000000

int N, K;
int dp[201][201];

int main(void) {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < 201; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < 201; i++) {
        dp[i][0] = 1;
        for (int j = 1; j < 201; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % DIVISOR;
        }
    }

    printf("%d", dp[K-1][N]);

    return 0;
}