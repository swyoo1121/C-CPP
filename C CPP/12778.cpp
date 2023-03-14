#include <iostream>

using namespace std;

int main() {
    int T, M, num_input;
    char type, char_input;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> M >> type;

        if (type == 'C') {
            for (int j = 0; j < M; j++) {
                cin >> char_input;
                cout << char_input - 64 << ' ';
            }
        }
        else if (type == 'N') {
            for (int j = 0; j < M; j++) {
                cin >> num_input;
                cout << (char)(num_input + 64) << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}