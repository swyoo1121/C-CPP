#include <stdio.h>

int main() {
    long long int S, sum = 0;
    int count = 0;

    scanf("%lld", &S);

    for (int i = 1; i < 100000; i++) {
        if (i + sum > S) break;

        sum += i;
        count++;
    }

    printf("%d\n", count);
    return 0;

}