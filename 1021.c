#include <stdio.h>

int main() {
    int N, M, input, amount, flag;
    int queue[53];

    int sum = 0, cnt_left = 0, cnt_right = 0, front, end;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        queue[i] = i + 1;
    }

    front = 0;
    end = N - 1;
    amount = N;

    for (int testcase = 0; testcase < M; testcase++) {
        scanf("%d", &input);
        flag = 0;
        
        while (input != queue[front]) {
            int swap = queue[front];
            for (int i = front; i < end; i++) {
                queue[i] = queue[i+1];
            }
            queue[end] = swap;
            cnt_left++;
            flag = 1;
        }

        cnt_right = amount - cnt_left;

        if (flag != 0 && cnt_left < cnt_right) sum += cnt_left;
        else if (flag != 0) sum += cnt_right;
        
        front++;
        amount--;
        cnt_left = 0;
    }

    printf("%d\n", sum);
    return 0;
}