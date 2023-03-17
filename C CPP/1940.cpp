#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int N, M, start, end, result = 0;
    int arr[15001];

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N, compare);
    start = 0;
    end = N - 1;

    while (start < end) {
        if (arr[start] + arr[end] == M) {
            result++;
            start++;
            end--;
        }
        else if (arr[start] + arr[end] < M) {
            start++;
        }
        else {
            end--;
        }
    }

    cout << result << endl;

    return 0;
}