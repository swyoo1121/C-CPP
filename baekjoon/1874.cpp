#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n, index = 1, target;
    bool flag = true;
    stack<int> s;
    queue<char> l;

    cin >> n;

    for (int iter = 0; iter < n; iter++) {
        cin >> target;

        if (s.empty() || s.top() < target) {
            while (index <= target) {
                s.push(index++);
                l.push('+');
            }
            s.pop();
            l.push('-');
        }
        else if (s.top() > target) {
            flag = false;
        }
        else {
            s.pop();
            l.push('-');
        }
    }

    if (flag) {
        while (!l.empty()) {
            cout << l.front() << '\n';
            l.pop();
        }
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}