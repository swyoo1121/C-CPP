#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0, X = 0;
    stack<int> S;

    cin >> N;

    while (N--) {
        int command = 0;
        cin >> command;

        switch (command) {
            case 1:
             int input;
             cin >> input;
             S.push(input);
             break;

            case 2:
            if (!S.empty()) {
                cout << S.top() << '\n';
                S.pop();
            }
            else cout << "-1" << '\n';
            break;

            case 3:
            cout << S.size() << '\n';
            break;

            case 4:
            if (S.empty()) cout << '1' << '\n';
            else cout << '0' << '\n';
            break;

            case 5:
            if (!S.empty()) cout << S.top() << '\n';
            else cout << "-1" << '\n';
            break;

            default:
            break;
        }
    }

    return 0;
}