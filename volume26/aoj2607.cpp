#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, x;
    cin >> n >> d >> x;

    vector<vector<int> > p(d, vector<int>(n));
    for (auto& i : p) for (auto& j : i) cin >> j;

    vector<int> dp(100001);
    dp[x] = 1;
    for (int i = 0; i < d-1; i++) {
        vector<int> s(100001);
        for (int j = 0; j < n; j++) {
            int sub = p[i+1][j] - p[i][j];
            if (sub <= 0) continue;
            for (int k = 0; k < 100001; k++) {
                if (k - p[i][j] >= 0) s[k] = max(s[k], s[k - p[i][j]] + sub);
            }
        }

        for (int j = 100000; j >= 0; j--)
            if (j + s[j] < 100001) dp[j + s[j]] |= dp[j];
    }

    int ans = 0;
    for (int i = 0; i < 100001; i++)
        ans = max(ans, dp[i] * i);

    cout << ans << endl;

    return 0;
}
