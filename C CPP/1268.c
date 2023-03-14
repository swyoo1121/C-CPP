    #include <stdio.h>

    int input[1000][6] = {0, };

    int main() {
        int N, result, flag, max = -1;
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%d", &input[i][j]);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                flag = 0;

                for (int j = 0; j < 5; j++) {
                    if (i != k && flag == 0) {
                        if (input[i][j] == input[k][j]) {
                            input[i][5]++;
                            flag = 1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (max < input[i][5]) {
                max = input[i][5];
                result = i + 1;
            }
        }

        printf("%d\n", result);

        return 0;
    }