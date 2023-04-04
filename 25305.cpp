#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, k, x;
    vector<int> v;

    cin >> N >> k;

    for (int iter = 0; iter < N; iter++) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.rbegin(), v.rend());

    cout << v[k-1] << endl;
    return 0;
}