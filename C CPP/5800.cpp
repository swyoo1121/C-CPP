#include <iostream>
#include <algorithm>

using namespace std;

int K, N, grade[51], maxs, mins, gap;

int main() {
    cin >> K;

    for (int testcase = 1; testcase <= K; testcase++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> grade[i];
        }

        sort(grade, grade + N);

        maxs = grade[0];
        mins = grade[0];
        gap = 0;

        for (int i = 1; i < N; i++) {
            if (maxs < grade[i]) maxs = grade[i];
            if (mins > grade[i]) mins = grade[i];
            if (gap < grade[i] - grade[i-1]) gap = grade[i] - grade[i-1];
        }

        cout << "Class " << testcase << '\n';
        cout << "Max " << maxs << ", Min " << mins << ", Largest gap " << gap << '\n';
    }
    return 0;

}