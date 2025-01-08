#include <stdio.h>

int main() {
    int n, sum, index, divisor[50000];

    while(1) {
        scanf("%d", &n);
        sum = 0;
        index = 0;

        if (n == -1) break;

        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                sum += i;
                divisor[index] = i;
                index++;
            }
        }

        if (sum == n) {
            printf("%d = ", n);
            for (int i = 0; i < index; i++) {
                printf("%d", divisor[i]);
                if (i != index - 1) printf(" + ");
            }
            printf("\n");
        }
        else {
            printf("%d is NOT perfect.\n", n);
        }

    }

    return 0;
}