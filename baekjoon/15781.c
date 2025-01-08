#include <stdio.h>

int main() {
    int N, M, input, max, result = 0;

    scanf("%d %d", &N, &M);

    max = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &input);
        if (input > max) max = input;
    }

    result += max;
    max = 0;

    for (int i = 0; i < M; i++) {
        scanf("%d", &input);
        if (input > max) max = input;
    }

    result += max;
    printf("%d\n", result);
    return 0;

}