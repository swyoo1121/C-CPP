#include <stdio.h>

int main() {
    int input, index = 0, result = 0, list[15] = {0, };

    while (1) {
        scanf("%d", &input);
        if (input == -1) break;
        else if (input != 0) {
            list[index] = input;
            index++;
        }
        else {
            for (int i = 0; i < index; i++) {
                int target = list[i] * 2;
                for (int j = 0; j < index; j++) {
                    if (target == list[j]) {
                        result++;
                        break;
                    }
                }
            }
            printf("%d\n", result);

            result = 0;
            index = 0;
        }
    }

    return 0;
}