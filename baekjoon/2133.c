#include <stdio.h>
//https://yabmoons.tistory.com/536
long long int dp[31];

int main() {
    int N;

    scanf("%d", &N);

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for (int i = 3; i <= N; i++) {
        if (i % 2) dp[i] = 0;
        else {
            dp[i] += dp[i-2] * 3;
            for (int j = 4; j <= i; j++) {
                dp[i] += dp[i-j] * 2;
            }
        }
    }

    printf("%lld", dp[N]);

    return 0;
}