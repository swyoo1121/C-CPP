#include <iostream>

using namespace std;

int R, C, ZR, ZC;

char scanner[51][51];

int main() {
    cin >> R >> C >> ZR >> ZC;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> scanner[i][j];
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int l = 0; l < ZR; l++) {
            for (int j = 1; j <= C; j++) {
                for (int k = 0; k < ZC; k++) cout << scanner[i][j];
            }

            cout << '\n';
        }
    }

    return 0;

}