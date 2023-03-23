#include <stdio.h>

int main() {
    int n;
    long long int TN[36] = {0, };

    TN[0] = 1;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            TN[i] += TN[j] * TN[i - j - 1];
        }
    }

    printf("%lld\n", TN[n]);
    return 0;
}