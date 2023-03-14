#include <iostream>

using namespace std;

int main() {
    double N, sum = 0, expect = 0, arr[101];

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
        expect += arr[i] / N;
    }

    double avg = sum / N;

    if (N == 0 || expect == 0) cout << "divide by zero" << endl;
    else {
        double result = avg / expect;
        printf("%.2f\n", result);
    }
    return 0;
}