#include <iostream>
#include <math.h>

using namespace std;

int N, start, link, result = 1000;
int arr[21][21] = {0, };
int selected[22] = {0, };

void dfs(int x, int pos) {
    if (x == N / 2) {
        start = 0;
        link = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (selected[i] == 1 && selected[j] == 1) start += arr[i][j];
                if (selected[i] == 0 && selected[j] == 0) link += arr[i][j];
            }
        }
    
        int temp = abs(start - link);
    	if (result > temp) result = temp;

	    return;
    }

    for (int i = pos; i < N; i++) {
        selected[i] = 1;
        dfs(x + 1, i + 1);
        selected[i] = 0;
    }
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0, 1);

    cout << result << endl;
    return 0;
}
