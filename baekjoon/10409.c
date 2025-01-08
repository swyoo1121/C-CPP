#include <stdio.h>

int main() {
    int n, T, input, count = 0;

    scanf("%d %d", &n, &T);

    for (int i = 0; i < n; i++) {
        scanf("%d", &input);

        if (T < input) break;
        else {
            count++;
            T -= input;
        }
    }
    printf("%d\n", count);
    return 0;
}