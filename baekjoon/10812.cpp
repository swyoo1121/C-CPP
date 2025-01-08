#include <iostream>

using namespace std;

int N, M, i,k, j;
int basket[105];

void rotate(int begin, int end, int mid) {
    int copy[105];
    int index = begin;

    for (int iter = mid; iter <= end; iter++) {
        copy[index] = basket[iter];
        index++;
    }

    for (int iter = begin; iter <= mid - 1; iter++) {
        copy[index] = basket[iter];
        index++;
    }

    
    for (int iter = begin; iter <= end; iter++) {
        basket[iter] = copy[iter];
    }
}

int main() {
    cin >> N >> M;

    for (int iter = 1; iter <= N; iter++) {
        basket[iter] = iter;
    }

    for (int cases = 1; cases <= M; cases++) {
        cin >> i >> j >> k;
        rotate(i, j, k);
    }

    for (int iter = 1; iter <= N; iter++) {
        cout << basket[iter] << ' ';
    }

}