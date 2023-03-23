#include <iostream>

using namespace std;

int N, M, i, j;
int basket[105];

void reverse(int left, int right) {
    int copy[105];
    int cursor = right;

    for (int iter = left; iter <= right; iter++) {
        copy[cursor] = basket[iter];
        cursor--;
    }

    for (int iter = left; iter <= right; iter++) {
        basket[iter] = copy[iter];
    }
}

int main() {
    cin >> N >> M;

    for (int iter = 1; iter <= N; iter++) {
        basket[iter] = iter;
    }

    for (int cases = 1; cases <= M; cases++) {
        cin >> i >> j;
        reverse(i, j);
    }

    for (int iter = 1; iter <= N; iter++) {
        cout << basket[iter] << ' ';
    }

}