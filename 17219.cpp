#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    map<string, string>input;

    int N, M;
    cin >> N >> M;

    string url;
    string password;

    for (int i = 0; i < N; i++) {
        cin >> url >> password;
        input.insert(make_pair(url, password));
    }

    for (int j = 0; j < M; j++) {
        cin >> url;
        cout << input[url] << endl;
    }

    return 0;
}