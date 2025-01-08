#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, input;
    long long int result = 0;
    vector<int> A;
    vector<int> B;

    cin >> N;

    for (int iter = 0; iter < N; iter++) {
        cin >> input;
        A.push_back(input);
    }

    for (int iter = 0; iter < N; iter++) {
        cin >> input;
        B.push_back(input);
    }

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    for (int iter = 0; iter < N; iter++) {
        result += A[iter] * B[iter];
    }

    cout << result << '\n';
    return 0;

}   