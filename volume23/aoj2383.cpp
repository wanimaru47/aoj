#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1000000007;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> v(N);
    for (auto& i : v) cin >> i;

    sort(v.begin(), v.end());

    vector<ll> dp(N);
    for (int i = 0; i < N; i++) {
        ll count = lower_bound(v.begin(), v.end(), v[i] - T) - v.begin();
        dp[i] = i - count + 1;
    }

    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ans *= dp[i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
