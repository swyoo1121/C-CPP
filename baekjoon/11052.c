#include <stdio.h>

int main() {
    int N, P[10001], dp[10001];

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &P[i]);
    }

    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        dp[i] = P[i];
        for (int j = 1; j <= i; j++) {
            dp[i] = dp[i-j] + P[j] > dp[i] ? dp[i-j] + P[j] : dp[i];
        }
    }

    printf("%d\n", dp[N]);
    return 0;
}