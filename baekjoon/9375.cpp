#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, n, result;
    string name, kind;
    
    cin >> T;

    for (int testcase = 0; testcase < T; testcase++) {
        cin >> n;
        map<string, int> wear;

        for (int i = 0; i < n; i++) {
            cin >> name >> kind;
            if (wear.find(kind) == wear.end()) {
                wear.insert({kind, 1});
            }
            else
                wear[kind]++;
        }

        result = 1;

        for (auto i : wear) {
            result *= (i.second + 1);
        }
        result -= 1;

        cout << result << '\n';
    }

    return 0;

}