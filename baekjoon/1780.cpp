#include <iostream>

using namespace std;

int paper[2188][2188];
int N;
int ones = 0, zeros = 0, minuses = 0;

void check(int posx, int posy, int range) {
    int flag = 0;
    int target = paper[posx][posy];

    for (int i = posx; i < posx + range; i++) {
        for (int j = posy; j < posy + range; j++) {
            if (target != paper[i][j]) flag = 1;

            if (flag == 1) break;
        }
        if (flag == 1) break;
    }

    if (flag == 1) {
        check(posx, posy, range / 3);
        check(posx + range / 3, posy, range / 3);
        check(posx + range / 3 * 2, posy, range / 3);
        check(posx, posy + range / 3, range / 3);
        check(posx + range / 3, posy + range / 3, range / 3);
        check(posx + range / 3 * 2, posy + range / 3, range / 3);
        check(posx, posy + range / 3 * 2, range / 3);
        check(posx + range / 3, posy + range / 3 * 2, range / 3);
        check(posx + range / 3 * 2, posy + range / 3 * 2, range / 3);
    }
    else {
        if (target == 1) ones++;
        else if (target == 0) zeros++;
        else minuses++;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    check(0, 0, N);

    cout << minuses << endl << zeros << endl << ones << endl;
    return 0;

}