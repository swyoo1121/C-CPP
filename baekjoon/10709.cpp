#include <iostream>

using namespace std;

int H, W;
int arr[101][101];
char sky[101][101];

int main() {
    cin >> H >> W;

    int minute = 0, flag = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> sky[i][j];
            arr[i][j] = -1;
        }
    }

    for (int i = 0; i < H; i++) {
        flag = 0;

        for (int j = 0; j < W; j++) {
            if (sky[i][j] == 'c') {
                minute = 1;
                flag = 1;
                arr[i][j] = 0;
            }
            else if (flag == 1) {
                minute++;
                arr[i][j] += minute;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}