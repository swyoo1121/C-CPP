#include <stdio.h>

#define MIN(X,Y) X < Y ? X : Y

int arr[100001] = {0, };

int main() {
    int N, S, length, left, right, sum;

    scanf("%d %d", &N, &S);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    length = N + 1;
    left = 0;
    right = 0;
    sum = arr[0];

    while (left <= right && right < N) {
        if (sum < S) {
            sum += arr[++right];
        }
        else {
            length = MIN(length, right - left + 1);
            sum -= arr[left++];
        }
    }

    if (length == N + 1) printf("0\n");
    else printf("%d\n", length);
    return 0;
}