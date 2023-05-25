#include <iostream>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main()
{
    int n, wine[10001];
    int dp[10001];
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }
    
    dp[0] = 0;
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i]);
        dp[i] = max(dp[i-1], dp[i]);
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
