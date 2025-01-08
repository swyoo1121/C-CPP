#include <stdio.h>

int checker(int number) {
    while (number > 0) {
        if (number % 10 != 4 && number % 10 != 7) return 1;
        else number /= 10;
    }

    return 0;
}

int main() {
    int N, result = 0;

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        if (checker(i) == 0) result = i;
    }

    printf("%d\n", result);
    return 0;
}