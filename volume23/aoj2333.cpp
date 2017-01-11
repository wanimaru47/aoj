#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    int n, m;
    const ll MOD = 1e9+7;
    cin >> n >> m;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());

    vector<ll> dp(m+1);
    vector<int> used(m+1);
    vector<int> t(m+1, 1000000000);
    dp[0] = 1LL;
    for (int i = 0; i < n; i++) {
        for (int j = m, s = 1000000000; j - v[i] >= 0; j--) {
            if (dp[j-v[i]]) {
                dp[j] += dp[j-v[i]];
                dp[j] %= MOD;
                used[j-v[i]] = true;
                if (i+1<n) {
                    t[j] = s = min(s, min(t[j-v[i]], v[i+1]));
                } else {
                    t[j] = min(t[j], s);
                }
            }
        }
        for (auto j : dp) cout << j << " "; cout << endl;
    }

    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        if (!used[i] && i + t[i] > m) {
            if (t[i] == 1000000000) {
                if (i + v[0] > m)
                    ans += dp[i];
            } else {
                ans += dp[i];
            }
        }
    }

    cout << ans << endl;

    return 0;
}
