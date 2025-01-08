#include <stdio.h>

int pascal[1001][1001] = {0, };

int main() {
    int N, K;
		
    scanf("%d %d", &N, &K);

    for (int i = 0; i <= N; i++) {
        pascal[i][0] = 1;
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j]) % 10007;
        }
    }

    printf("%d\n", pascal[N][K]);
    return 0;
}