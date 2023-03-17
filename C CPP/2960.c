#include <stdio.h>

int main() {
    int N, K, index = 2, flag = 1, result = 2, arr[1001] = {0, };

    scanf("%d %d", &N, &K);

    for (int i = 2; i <= N; i++) {
        arr[i] = 1;
    }

    while (1) {
        if (arr[index] == 1) {
            K--;

            if (K == 0) {
                result = index;
                break;
            }

            for (int i = index + 1; i <= N; i++) {
                if (i % index == 0) {
                    if (arr[i] == 1) {
                        arr[i] = 0;
                        K--;

                        if (K == 0) {
                            result = i;
                            flag = 0;
                            break;
                        }
                    }
                }
            }

            if (flag == 0) break;
        }
        index++;
    }

    printf("%d\n", result);
    return 0;
}