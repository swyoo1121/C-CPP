#include <stdio.h>
#include <math.h>
//https://pacific-ocean.tistory.com/166
int main() {
    int N, sum, spare, length;

    sum = 0;
    length = 0;
    scanf("%d", &N);

    spare = N;

    while (spare > 0) {
        length++;
        spare /= 10;
    }

    length--;

    while (spare < length) {
        sum += 9 * pow(10, spare) * (spare + 1);
        spare++;
    }

    sum += ((N - pow(10, length)) + 1) * (length + 1);

    printf("%d", sum);

    return 0;
}