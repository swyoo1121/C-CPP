#include <stdio.h>

#define MAX(A,B) ((A > B) ? A : B)

int T, n;
int arr[2][100001];

int main(void) {
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        int dp[2][100001] = {0, };

        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &arr[j][k]);
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 2; k++) {
                if (j == 0) dp[k][j] = arr[k][j];
                else if (k == 0) dp[k][j] = MAX(dp[k][j-1], dp[k+1][j-1] + arr[k][j]);
                else dp[k][j] = MAX(dp[k][j-1], dp[k-1][j-1] + arr[k][j]);
            }
        }

        printf("%d\n", MAX(dp[0][n-1], dp[1][n-1]));

    }
    
    return 0;
}