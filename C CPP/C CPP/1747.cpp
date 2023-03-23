#include <iostream>

using namespace std;

int arr[1004001] = {0, };
int N;

int reverse(int n) {
    int sum = 0;

    while (n > 0) {
        sum *= 10;
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main() {
    arr[1] = 1;

    for (int i = 2; i <= 1004000; i++) {
        if (arr[i] == 1) continue;
        else {
            arr[i] = 0;
            int multi = 2;
            while (i * multi <= 1004000) {
                arr[i * multi] = 1;
                multi++;
            }
        }
    }

    cin >> N;

    for (int i = N; i <= 1004000; i++) {
        if (arr[i] == 0) {
            if (i == reverse(i)) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;

}