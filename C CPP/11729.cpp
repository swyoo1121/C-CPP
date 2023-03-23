#include <iostream>
#include <cmath>

using namespace std;

int hanoi(int n, int from, int to, int via) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return 1;
    }
    else return hanoi(n - 1, from, via, to) + hanoi(1, from, to, via) + hanoi(n - 1, via, to, from);
}

int main() {
    int N, K;
    cin >> N;
    K = pow(2, N) - 1;

    cout << K << '\n';
    hanoi(N, 1, 3, 2);
    return 0;
}