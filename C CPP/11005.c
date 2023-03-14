#include <stdio.h>

int main() {
    int N, B, length = 0;
    char alpha[36], result[32];

    for (int i = 0; i < 36; i++) {
        if (i < 10) alpha[i] = 48 + i;
        else alpha[i] = 55 + i;
    }

    scanf("%d %d", &N, &B);

    while (N > 0) {
        result[length] = alpha[N % B];
        length++;
        N /= B;
    }

    for (int i = length - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }

    printf("\n");
    return 0;
}