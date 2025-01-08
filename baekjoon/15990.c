#include <stdio.h>

long long int dp[100001][3] = {0, };

int main() {
    int T, n;

    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;

    scanf("%d", &T);

    for (int i = 4; i < 100001; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % 1000000009;
        dp[i][1] = (dp[i-2][0] + dp[i-2][2]) % 1000000009;
        dp[i][2] = (dp[i-3][0] + dp[i-3][1]) % 1000000009;
    }

    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%lld\n", (dp[n][0] + dp[n][1] + dp[n][2]) % 1000000009);
    }

    return 0;
}