#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;

    bool is_prime[1000001];
    for (int i = 0; i <= 1000000; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 0; i <= 1000000/2; i++) {
        if (is_prime[i])
            for (int j = 2; j * i <= 1000000; j++) {
                is_prime[i * j] = false;
            }
    }

    while (cin >> N >> K, N || K) {
        vector<int> v(N);
        for (auto& i : v) cin >> i;

        vector<bool> dp(K+1, false);
        dp[0] = true;
        int ans = -1;
        for (int i = 0; i < K; i++) {
            if (dp[i]) {
                for (auto j : v) {
                    if (i + j <= K) dp[i + j] = true;
                    if (i + j <= K && is_prime[i+j])
                        ans = max(ans, i + j);
                }
            }
        }

        if (ans >= 0) cout << ans << endl;
        else cout << "NA" << endl;
    }

    return 0;
}
