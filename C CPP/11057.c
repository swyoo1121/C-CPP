#include <stdio.h>

int dp[1001][10] = {0, };

int main() {
    int N, result = 0;
    
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    scanf("%d", &N);

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        result += dp[N][i];
        result %= 10007;
    }

    printf("%d\n", result);
    return 0;
    
}