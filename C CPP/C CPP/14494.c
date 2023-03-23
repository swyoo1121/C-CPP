#include <stdio.h>
#define MAX 1000000007

long long int dp [1001][1001] = {0, };

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= 1000; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i-1][j-1] % MAX + dp[i-1][j] % MAX + dp[i][j-1] % MAX) % MAX;
        }
    }

    printf("%lld", dp[n][m]);
}