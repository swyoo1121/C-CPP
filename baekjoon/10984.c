#include <stdio.h>

int main() {
    int T, N, C, degree;
    double G, grade;

    scanf("%d", &T);

    for (int i = 0 ; i < T; i++) {
        scanf("%d", &N);
        degree = 0;
        grade = 0;

        for (int j = 0; j < N; j++) {
            scanf("%d %lf", &C, &G);
            degree += C;
            grade += C * G;
        }
        printf("%d %.1lf\n", degree, grade / degree);
    }

    return 0;
}