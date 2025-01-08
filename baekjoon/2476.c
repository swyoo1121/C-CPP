#include <stdio.h>

int main() {
    int N, fir, sec, thi, max;

    scanf("%d", &N);
    max = 0;

    for (int i = 0; i < N; i++) {
        int result = 0;
        scanf("%d %d %d", &fir, &sec, &thi);

        if (fir == sec && sec == thi) result = 10000 + fir * 1000;
        else if (fir == sec || sec == thi || thi == fir) {
            if (fir == sec) result = 1000 + fir * 100;
            else if (sec == thi) result = 1000 + sec * 100;
            else result = 1000 + thi * 100;
        }
        else {
            if (fir > sec && fir > thi) result = fir * 100;
            else if (sec > fir && sec > thi) result = sec * 100;
            else result = thi * 100;
        }

        if (max < result) max = result;
    }

    printf("%d\n", max);
    return 0;
}