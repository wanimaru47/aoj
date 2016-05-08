#include <bits/stdc++.h>
using namespace std;

long long int dp[4001];

int main() {
    int n;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            dp[i + j]++;
        }
    }
    while (cin >> n) {
        long long int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += dp[i] * dp[n - i];
        }

        cout << ans << endl;
    }

    return 0;
}
