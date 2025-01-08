#include <iostream>

using namespace std;

int students;
int line[101] = {0, };

int main() {
    cin >> students;

    for (int i = 1; i <= students; i++) {
        int input;

        cin >> input;

        for (int j = i; j > i - input; j--) {
            line[j] = line[j - 1];
        }
        line[i - input] = i;
    }

    for (int i = 1; i <= students; i++) {
        cout << line[i] << ' ';
    }

    cout << endl;
    return 0;
}