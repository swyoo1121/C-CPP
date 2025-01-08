#include <stdio.h>

long long int arr[1000001] = {0, };

int main() {
    long long int min, max;
    int result = 0;

    scanf("%lld %lld", &min, &max);

    for (long long int i = 2; i * i <= max; i++) {
        long long int n = min / (i * i);

        if (min % (i * i)) n++;

        while (n * i * i <= max) {
            arr[n * i * i - min] = 1;
            n++;
        }
    }

    for (int i = 0; i <= max - min; i++) {
        if (arr[i] == 0) result++;
    }

    printf("%d\n", result);
    return 0;
}