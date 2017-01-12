#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    int n, m;
    const ll MOD = 1e9+7;
    cin >> n >> m;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    v.push_back(1<<26);
    sort(v.begin(), v.end());
    auto sum = v;
    for (int i = 0; i < n; i++)
        sum[i] += sum[i-1];

    ll ans = 0;
    for (int i = 1; i <= n+1; i++) {
        if (sum[i-1] > m) break;

        vector<ll> dp(m+1);
        vector<int> used(m+1);
        dp[sum[i-1]] = 1LL;

        for (int j = i + 1; j <= n; j++) {
            for (int k = m; k - v[j] >= sum[i-1]; k--) {
                if (dp[k - v[j]]) {
                    dp[k] += dp[k - v[j]];
                    dp[k] %= MOD;
                    used[k - v[j]] = true;
                }
            }
        }

        for (int j = 1; j <= m; j++) {
            if (!used[j] && j + v[i] > m) {
                ans += dp[j];
                ans %= MOD;
            }
        }
    }

    cout << max(ans,1LL) << endl;

    return 0;
}
