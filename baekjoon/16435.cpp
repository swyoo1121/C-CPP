#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int N, L;
    int h[10001];

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    sort(h, h + N, compare);

    for (int i = 0; i < N; i++) {
        if (h[i] > L) break;
        else L++;
    }

    cout << L << endl;
    return 0;
}