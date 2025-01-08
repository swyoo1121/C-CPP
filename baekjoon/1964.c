#include <stdio.h>

int main() {
    int N, point = 7, result = 5;

    scanf("%d", &N);

    for (int i = 1; i < N; i++) {
        result = (result + point) % 45678;
        point += 3;
    }

    printf("%d\n", result);
    return 0;

}