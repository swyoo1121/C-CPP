#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, left, right, index;
    int arr[9];

    cin >> N;
    left = 0;
    right = 0;
    index = 0;

    while (N > 0) {
        arr[index] = N % 10;
        index++;
        N /= 10;
    }

    for (int i = 0; i < index; i++) {
        if (i <= index / 2 - 1) left += arr[i];
        else right += arr[i];
    }

    if (left == right) cout << "LUCKY" << endl;
    else cout << "READY" << endl;

    return 0;
    
}