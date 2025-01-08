#include <stdio.h>

int arr[10][10];
int max = 0;

int main(void) {
    int row = 1;
    int col = 1;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
                row = i;
                col = j;
            }
        }
    }

    printf("%d \n%d %d", max, row, col);
    return 0;
}