#include <stdio.h>

int main() {
    int N, flag, input[201][4] = {0, };

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &input[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            flag = 0;
            for (int k = 0; k < N; k++) {
                if (k == i) continue;
                
                if (input[k][j] == input[i][j]) {
                    flag = 1;
                    break;
                }
            }
            
            if (flag == 0) input[i][3] += input[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", input[i][3]);
    }
    return 0;
}