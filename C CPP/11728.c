#include <stdio.h>

int A[1000001], B[1000001], C[2000001];
    
int main(void) {
    int N, M, indexA, indexB, indexC;

    indexA = 0;
    indexB = 0;
    indexC = 0;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    for (int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }

    while (indexA < N && indexB < M) {
        if (A[indexA] > B[indexB]) {
            C[indexC] = B[indexB];
            indexB++;
            indexC++;
        }
        else {
            C[indexC] = A[indexA];
            indexA++;
            indexC++;
        }
    }

    if (indexA < N) {
        for (int i = indexA; i < N; i++) {
            C[indexC] = A[i];
            indexC++;
        }
    }
    
    if (indexB < M) {
        for (int i = indexB; i < M; i++) {
            C[indexC] = B[i];
            indexC++;
        }
    }

    for (int i = 0; i < indexC; i++) {
        printf("%d ", C[i]);
    }
    
    return 0;
}