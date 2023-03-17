#include <stdio.h>

int n;
int myIndex = 0;
int count = 1;
int maxim = 0;
int stack[100001];
char result[200001];

void push() {
    stack[myIndex] = count;
    myIndex++;
    count++;
    result[maxim] = '+';
    maxim++;
}

void pop() {
    myIndex--;
    stack[myIndex] = 0;
    result[maxim] = '-';
    maxim++;
}

int main() {
    int input, flag;
    scanf("%d", &n);
    flag = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        if (input > count) {
            while (input >= count) push();
            pop();
        }
        else if (input < count) {
            if (stack[myIndex - 1] > input) {
                flag = 1;
            }
            pop();
        }
        else {
            push();
            pop();
        }
    }

    if (flag == 0) {
        for (int i = 0; i < maxim; i++) {
            printf("%c\n", result[i]);
        }
    }
    else if (flag == 1) {
        printf("NO\n");
    }

    return 0;
}