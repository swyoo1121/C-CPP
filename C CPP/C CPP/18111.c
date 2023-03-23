#include <stdio.h>

int main() {
	int N, M, B;
    int arr[501][501];
	int gap[2] = {0, };
	int flag = 0;
	int min = 192000000, height = 0, B_temp, sum;

    scanf("%d %d %d", &N, &M, &B);
    B_temp = B;

	for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
	}

	for (int i = 0; i <= 256; i++) {
		for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
				if (arr[j][k] > i) {
					gap[0] += arr[j][k] - i;
					B += arr[j][k] - i;
				}
			}
		}

		for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
				if (arr[j][k] <= i) {
					gap[1] += i - arr[j][k];
					B -= i - arr[j][k];
				}

				if (B < 0) {
                    gap[1] = 64000000;
                    gap[0] = 64000000;
                    flag = 1;
                    break;
                }
			}
			if (flag == 1) {
                flag = 0;
                break;
            }
		}

		sum = (gap[0] * 2) + (gap[1]);

		if (sum < min) {
            min = sum;
            height = i;
        }
        else if (sum == min) {
            if (height < i) height = i;
        }

		gap[0] = 0;
        gap[1] = 0;
        B = B_temp;
	}

	printf("%d %d", min, height);
    return 0;
}