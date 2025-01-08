#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main() {
    int N, x;
    priority_queue<int, vector<int>, greater<int>> pq;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int iter = 0; iter < N; iter++) {
        cin >> x;

        if (x == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }

    return 0;
}