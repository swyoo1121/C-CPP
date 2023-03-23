#include <stdio.h>

int main() {
    int N, index = 0, result = 0, multi = 1;
    char binary[33] = {0, };

    scanf("%d", &N);

    while (N > 0) {
        binary[index] = N % 2 + 48;
        index++;
        N /= 2;
    }

    while (index > 0) {
        index--;
        result += (binary[index] - '0') * multi;
        multi *= 2;
    }

    printf("%d\n", result);
    return 0;
}