#include <iostream>

using namespace std;

int T, N, result = 0;
int arr[1000001];

void set(int n) {
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
    }

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) {
            for (int j = 2; i * j <= n; j++) {
                arr[i*j] = 1;
            }
        }
        else continue;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> N;

        set(N);
        for (int i = 0; i <= N/2; i++) {
            if (arr[i] + arr[N-i] == 0) result++;
        }
        cout << result << '\n';
        result = 0;
    }

    return 0;    
}