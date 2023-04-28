#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, result = 0;
    string input;
    map<string, bool> ma;

    cin >> N >> M;

    for (int iter = 0; iter < N; iter++) {
        cin >> input;
        ma.insert(pair<string, bool>(input, true));
    }

    for (int iter = 0; iter < M; iter++) {
        cin >> input;
        if (ma[input]) result++;
    }
    cout << result << endl;
    return 0;
}