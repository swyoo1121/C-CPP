#include <stdio.h>

int main() {
    int V, count = 0;
    char vote;

    scanf("%d ", &V);

    for (int i = 0; i < V; i++) {
        scanf("%c", &vote);
        
        if (vote == 'A') count++;
        else count--;
    }

    if (count > 0) printf("A\n");
    else if (count < 0) printf("B\n");
    else printf("Tie\n");

    return 0;
}