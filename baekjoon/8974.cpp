#include <iostream>

using namespace std;

int main() {
    int A, B, arr[1001], limit = 1, iter = 0, sum = 0;

    cin >> A >> B;

    for (int i = 1; i <= B; i++) {    
        if (iter < limit) {
            arr[i] = limit;
            iter++;
        }
        else {
            limit++;
            iter = 1;
            arr[i] = limit;
        }
    }

    for (int i = A; i <= B; i++) {
        sum += arr[i];
    }

    cout << sum << endl;
    return 0;
}