#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int base;
    cin >> base;

    vector<int> opt(N);
    for (auto& i : opt) cin >> i;

    vector<vector<int> > dp(N + 1, vector<int>(N + 1));
    dp[0][0] = base;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + opt[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        ans = max(dp[N][i] / (A + i * B), ans);
    }

    cout << ans << endl;

    return 0;
}
