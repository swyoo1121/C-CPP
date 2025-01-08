#include <iostream>

using namespace std;

int main() {
    long long N, oil, min = 1000000001, dist[100001];
    long long sum = 0;

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> dist[i];
    }

    for (int i = 0; i < N - 1; i++) {
        cin >> oil;
        if (min > oil) min = oil;

        sum += min * dist[i];
    }

    cout << sum << endl;
    return 0;
}