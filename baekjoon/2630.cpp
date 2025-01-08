#include <iostream>

using namespace std;

int blue = 0, white = 0;

int input[130][130];

void check(int pos_x, int pos_y, int length) {
    int flag = input[pos_x][pos_y];

    for (int i = pos_x; i < pos_x + length; i++) {
        for (int j = pos_y; j < pos_y + length; j++) {
            if (input[i][j] != flag) {
                flag = 2;
                break;
            }
        }

        if (flag == 2) break;
    }

    if (flag == 2) {
        check(pos_x, pos_y, length / 2);
        check(pos_x + length / 2, pos_y, length / 2);
        check(pos_x, pos_y + length / 2, length / 2);
        check(pos_x + length / 2, pos_y + length / 2, length / 2);
    }
    else if (flag == 1) {
        blue++;
    }
    else {
        white++;
    }
}

int main() {
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> input[i][j];
        }
    }

    check(1, 1, N);

    cout << white << endl << blue << endl;
    return 0;
}