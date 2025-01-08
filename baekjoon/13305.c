#include <stdio.h>

long long int N, min, price, road[100001];
long long int result = 0;

int main() {
    scanf("%lld", &N);
    min = 1000000001;
    price = 0;

    for (int i = 0; i < N - 1; i++) {
        scanf("%lld", &road[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        scanf("%lld", &price);

        if (min > price) min = price;

        result += road[i] * min;
    }

    printf("%lld\n", result);
    return 0;
}