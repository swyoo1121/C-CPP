#include <stdio.h>

#define MAX(A, B) ((A > B) ? A : B)

int N, T[16], P[16];
int dp[16] = {0, };

int main(void) {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }

    for (int i = N; i >= 1; i--) {
        if (i + T[i] > N + 1) dp[i] = dp[i+1];
        else dp[i] = MAX(dp[i+1], dp[i+T[i]] + P[i]);
    }

    printf("%d", dp[1]);
    return 0;

}