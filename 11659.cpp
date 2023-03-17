#include <iostream>

using namespace std;

int N, M, input, arr[100001];
int i, j;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    arr[0] = 0;

    for (int a = 1; a <= N; a++) {
        cin >> input;
        if (a == 1) arr[a] = input;
        else arr[a] = arr[a - 1] + input;
    }

    for (int a = 0; a < M; a++) {
        cin >> i >> j;
        cout << arr[j] - arr[i - 1] << '\n';
    }
    return 0;
}