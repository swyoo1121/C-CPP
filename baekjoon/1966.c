#include <stdio.h>

typedef struct printer {
    int priority;
    int index;
} Printer;

int main() {
    int T, N, M, end, flag, cnt;
    Printer arr[5051];

    scanf("%d", &T);

    for (int testcase = 0; testcase < T; testcase++) {
        scanf("%d %d", &N, &M);
        end = N;
        cnt = 0;

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i].priority);
            arr[i].index = i;
        }

        for (int i = 0; i < end; i++) {
            flag = 0;
            for (int j = i + 1; j < end; j++) {
                if (arr[j].priority > arr[i].priority) {
                    arr[end].priority = arr[i].priority;
                    arr[end].index = arr[i].index;
                    end++;
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                cnt++;
                if (arr[i].index == M) {
                    printf("%d\n", cnt);
                    break;
                }
            }
        }
    }

    return 0;
}