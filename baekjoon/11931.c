#include <stdio.h>
#include <stdlib.h>

int arr[1000001] = {0, };

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 > num2) return -1;
    if (num1 < num2) return 1;

    return 0;
}

int main() {
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}