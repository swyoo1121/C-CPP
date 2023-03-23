#include <iostream>

using namespace std;

int arr[1001];

int main() {
    int N;
    cin >> N;

    arr[0] = 1;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 0;
    arr[4] = 1;

    for (int i = 5; i <= N; i++) {
        if (arr[i - 1] == 1 && arr[i - 3] == 1 && arr[i - 4] == 1) arr[i] = 0;
        else arr[i] = 1;
    }

    if (arr[N] == 1) cout << "SK" << endl;
    else cout << "CY" << endl;
    return 0;
}