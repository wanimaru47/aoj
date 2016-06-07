#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

const int INF = 1 << 28;

int N, T;

void solve() {
    vec t(T);
    for (auto& i : t) cin >> i;
    cin >> N;
    vec d(N), h(N);
    for (int i = 0; i < N; i++) {
        cin >> d[i] >> h[i];
        d[i]--;
    }

    vec times(101, INF);
    for (int i = 0; i < N; i++) {
        times[d[i]] = min(times[d[i]], h[i]);
    }

    mat dp(101, vec(T, INF));
    dp[0][0] = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < T; j++) {
            if (dp[i][j] == INF) continue;
            int next = (j + 1) % T;
            // use
            dp[i+1][0] = min(dp[i+1][0], dp[i][j] + 1);
            // do not using
            if (t[next] <= times[i+1]) {
                dp[i+1][next] = min(dp[i+1][next], dp[i][j]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < T; i++) {
        ans = min(ans, dp[100][i]);
    }

    cout << ans << endl;
}

int main() {
    while (cin >> T, T) solve();
}
