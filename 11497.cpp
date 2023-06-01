#include <iostream>

using namespace std;

int main() {
    int N, P[10001], dp[10001];

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = P[i];
        for (int j = 1; j <= i; j++) {
            dp[i] = dp[i-j] + P[j] > dp[i] ? dp[i-j] + P[j] : dp[i];    
        }
    }

    cout << dp[N] << endl;
    return 0;
}