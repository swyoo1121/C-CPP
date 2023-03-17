#include <iostream>

using namespace std;

#define MIN(A, B) A < B ? A : B;

int main() {
    int dp[10001] = {0, };
    int coin[101];
    int n, k;

    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        dp[i] = 10001;
    }

    for (int i = 1; i <= n; i++) {
        cin >> coin[i];

        for (int j = coin[i]; j <= k; j++) {
            dp[j] = MIN(dp[j], dp[j - coin[i]] + 1);
        }
    }

    if (dp[k] == 10001) cout << -1 << endl;
    else cout << dp[k] << endl;

    return 0;
}