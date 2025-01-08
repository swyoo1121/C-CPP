#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define Limit 8001

int main(void) {
    int i, j = 0, k = 0, n, num, mid, mode = 0, size;
    int sum = 0, max_num = 0;

    scanf("%d", &num);

    int *arr = (int*)malloc(sizeof(int)*num);
    int count[Limit] = {0, };
    int max[Limit] = {0, };

    for (i = 0; i < num; i++) {
        scanf("%d", &n);
        sum = sum + n;
        max[n + 4000]++;
    }

    double avg = round(sum / (double)num);
    if (avg == -0) avg = 0;

    for (i = 0; i < Limit; i++) {
        if (max[i] > max_num) {
            j = 0;
            max_num = max[i];
            count[j] = i - 4000;
            j++;
        }
        else if (max[i] == max_num) {
            count[j] = i - 4000;
            j++;
        }

        if (max[i]>0) {
            while (max[i]>0) { 
                arr[k++] = i - 4000;
                max[i]--;
            }
        }
    }

    if (j == 1) {
        mode = count[0];
    }
    else if (j > 1) {
        mode = count[1];
    }
    mid = arr[(num - 1) / 2];
    size = arr[num - 1] - arr[0];

    printf("%.f\n", avg);
    printf("%d\n", mid);
    printf("%d\n", mode);
    printf("%d", size);
    free(arr);

    return 0;
}
