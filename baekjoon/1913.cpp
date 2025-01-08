#include <iostream>

using namespace std;

int result[1000][1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, xi, yi, index, turn, limit, target, target_x, target_y;

    cin >> N;
    cin >> target;

    xi = N / 2;
    yi = xi;
    index = 1;
    turn = 0;
    limit = 1;

    result[xi][yi] = index;

    while (index < N * N) {
        if (turn == 0) {
            for (int k = 0; k < limit; k++){ 
                result[--xi][yi] = ++index;

                if (index == N * N) break;
            }
        }
        else if (turn == 1) {
            for (int k = 0; k < limit; k++) result[xi][++yi] = ++index;
            limit++;
        }
        else if (turn == 2) {
            for (int k = 0; k < limit; k++) result[++xi][yi] = ++index;
        }
        else if (turn == 3) {
            for (int k = 0; k < limit; k++)
                result[xi][--yi] = ++index;
            limit++;
        }

        turn = (turn + 1) % 4;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << ' ';
            if (result[i][j] == target) {
                target_x = i;
                target_y = j;
            }
        }
        cout << '\n';
    }

    cout << target_x + 1 << ' ' << target_y + 1 << '\n';
    return 0;    
}