#include <stdio.h>

int main() {
    int N, W, H, L;

    scanf("%d %d %d %d", &N, &W, &H, &L);

    if ( (W / L) * (H / L) > N) printf("%d\n", N);
    else printf("%d\n", (W / L) * (H / L));

    return 0;
}