#include <stdio.h>

int main() {
    int N, mount[30001], point, count, max;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &mount[i]);
    }

    count = 0;
    max = 0;
    point = mount[0];

    for (int i = 1; i < N; i++) {
        if (point > mount[i]) count++;
        else {
            if (max < count) max = count;
            point = mount[i];
            count = 0;
        }

        if (max < count) max = count;
    }

    printf("%d\n", max);
    return 0;
}