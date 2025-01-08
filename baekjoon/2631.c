#include <stdio.h>

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {
    int N, result, length[201], input[201];

    scanf("%d", &N);
    result = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }

    for (int i = 0; i < N; i++) {
        length[i] = 1;
        for (int j = 0; j < i; j++) {
            if (input[j] < input[i]) {
                length[i] = max(length[i], length[j] + 1);
            }
        }

        if (result < length[i]) result = length[i];
    }

    printf("%d\n", N - result);
    return 0;

}