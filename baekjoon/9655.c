#include <stdio.h>

int main(void) {
    int N;
    
    scanf("%d", &N);

    printf("%s", N % 2 == 0 ? "CY" : "SK");
    
    return 0;
}