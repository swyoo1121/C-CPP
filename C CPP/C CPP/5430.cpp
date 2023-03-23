#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, T;

    cin >> T;

    while (T--) {
        string p, input;
        bool reverse = false, error = false;
        deque<int> dq;

        cin >> p;
        cin >> n;
        cin >> input;
        string s = "";

        for (int i = 0; i < input.length();i++) {
            if (isdigit(input[i])) {
                s += input[i];
            }
            else {
                if (!s.empty()) {
                    dq.push_back(stoi(s));
                    s = "";
                }
            }
        }

        for (auto o : p) {
            if (o == 'R') {
                if (reverse)
                    reverse = false;
                else
                    reverse = true;
            }
            else {
                if (dq.empty()) {
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                if (reverse)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if (!error) {
            cout << '[';
        }

        if (reverse && !dq.empty()) {
            for (auto o = dq.rbegin(); o != dq.rend(); o++) {
                if (o == dq.rend() - 1)
                    cout << *o;
                else cout << *o << ',';
            }
        }
        else if (!reverse && !dq.empty()){
            for (auto o = dq.begin(); o != dq.end(); o++) {
                if (o == dq.end() - 1)
                    cout << *o;
                else cout << *o << ',';
            }
        }

        if(!error)
        cout << "]\n";
    }
}