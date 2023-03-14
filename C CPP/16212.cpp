#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int input;

    for (int i = 0; i < N; i++) {
        cin >> input;
        a.push_back(input);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }

    cout << '\n';
    return 0;
}