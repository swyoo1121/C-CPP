#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int input, max, count, N[30000];

    scanf("%d", &input);

    max = 0;
    count = 0;

    for (int i = 0; i < input; i++) {
        scanf("%d", &N[i]);
    }

    for (int i = 0; i < input; i++) {
        if (N[i] > N[i+1]) {
            count++;
            continue;
        }
        else {
            if (max < count) max = count;
            count = 0;
            continue;
        }
    }

    printf("%d", max);
    return 0;
}