#include <iostream>

using namespace std;

int main() {
    int arr[3];

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];

        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                int swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
            }
        }
    }

    if (arr[2] - arr[1] == arr[1] - arr[0]) cout << arr[2] + arr[1] - arr[0] << endl;
    else cout << arr[2] - arr[1] + arr[0] << endl;

    return 0;
    
}