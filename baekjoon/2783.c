#include <stdio.h>

int main(void) {
    int N;
    double X, Y, price, result;

    scanf("%lf %lf", &X, &Y);
    result = 1000 / Y * X;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%lf %lf", &X, &Y);
        price = 1000 / Y * X;
        if (result > price) result = price;
    }

    printf("%.2lf", result);

    return 0;    
}