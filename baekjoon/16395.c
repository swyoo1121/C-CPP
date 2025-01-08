#include <stdio.h>

int main() {
    int dp[31][31] = {0, };
    int n, k;

    for (int i = 1; i < 31; i++) {
        dp[i][1] = 1;
    }

    for (int i = 1; i < 31; i++) {
        for (int j = 2; j < 31; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    scanf("%d %d", &n, &k);

    printf("%d\n", dp[n][k]);
    return 0;
}