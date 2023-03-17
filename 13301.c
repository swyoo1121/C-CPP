#include <stdio.h>

int main() {
    int N;
    long long int dp[81];

    scanf("%d", &N);

    dp[1] = 4;
    dp[2] = 6;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    printf("%lld\n", dp[N]);
    return 0;
}