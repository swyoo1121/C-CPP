#include <iostream>
#include <algorithm>

using namespace std;

int tree[1000001];

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int N, result = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    sort(tree, tree + N, compare);

    for (int i = 0; i < N; i++) {
        int temp = tree[i] + i + 1;
        if (result < temp) result = temp;
    }

    cout << result + 1 << endl;
    return 0;
}