#include <iostream>

using namespace std;

int N, result = 0, maxi = 0, arr[5];

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[j];
        }

        for (int a = 0; a <= 2; a++) {
            for (int b = a + 1; b <= 3; b++) {
                for (int c = b + 1; c <= 4; c++) {
                    if (maxi <= (arr[a] + arr[b] + arr[c]) % 10) {
                        maxi = (arr[a] + arr[b] + arr[c]) % 10;
                        result = i;
                    }
                }
            }
        }
    }

    cout << result << endl;
    return 0;
}