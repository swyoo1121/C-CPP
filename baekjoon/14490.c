#include <stdio.h>

int euclid(int a, int b) {
    int c = 0;

    while (1) {
        if (a % b == 0) {
            return b;
        }
        c = a % b;
        a = b;
        b = c;
    }
}

int main() {
    int n, m;

    scanf("%d:%d", &n, &m);

    if (n > m) printf("%d:%d\n", n / euclid(n, m), m / euclid(n, m));
    else printf("%d:%d\n", n / euclid(m, n), m / euclid(m, n));

    return 0;
}