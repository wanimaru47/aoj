#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int N;
void solve() {
    vector<int> shop(N);
    for (auto& i : shop) cin >> i;

    vector<int> diff(N);
    for (int i = 0; i < N; i++) {
        int d = shop[i] % 1000;
        if (d == 0) diff[i] = 500;
        else if (d < 500) diff[i] = 0;
        else diff[i] = d - 500;
    }

    vector<vector<P> > dp(N + 1, vector<P>(500 * N + 1, P(-1, 0)));
    dp[0][0] = P(0, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 500 * i; j++) {
            auto coin = dp[i][j];
            if (coin.first == - 1) continue;
            dp[i+1][j] = max(dp[i+1][j], coin);
            if (diff[i] == 0) {
                P ncoin = P(coin.first + 1, coin.second - shop[i]);
                int f = j + 500 - (shop[i] % 1000);
                dp[i+1][f] = max(dp[i+1][f], ncoin);
            } else {
                if (diff[i] <= j) {
                    P ncoin = P(coin.first + 1, coin.second - shop[i]);
                    int f = j - diff[i];
                    dp[i+1][f] = max(dp[i+1][f], ncoin);
                }

                P pcoin = P(coin.first, coin.second - shop[i]);
                int f_ = j + (shop[i] % 1000 ? 1000 - shop[i] % 1000 : 0);
                dp[i+1][f_] = max(dp[i+1][f_], pcoin);
            }
        }
    }

    P ans(0, 0);
    for (auto p : dp[N]) {
        ans = max(ans, p);
    }

    cout << ans.first << " " << -ans.second << endl;
}

int main() {
    while (cin >> N, N) solve();

    return 0;
}
