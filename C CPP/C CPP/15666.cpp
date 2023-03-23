#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int ans[9];
int typing[9];
int N, M, input;

void recursion(int x, int len) {
    if (len == M) {
        for (int i = 0; i < M; i++)
            printf("%d ",ans[i]);
        printf("\n");
        return;
    }

    int last = 0;

    for (int i = x; i < N; i++) {
        if (typing[i] != last) {
            ans[len] = typing[i];
            last = ans[len];
            recursion(i,len+1);
        }
    }

    return;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> typing[i];
    }

    sort(typing, typing + N);

    recursion(0, 0);
    return 0;
}