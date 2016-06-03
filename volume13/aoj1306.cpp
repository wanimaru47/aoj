#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> PP;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef vector<mat> space;

const int INF = 1 << 28;

void solve(int N) {
    vector<int> p(N+1), t(N+1);
    p[0] = t[0] = 0;
    for (int i = 1; i <= N; i++) cin >> p[i] >> t[i];

    mat dp(N+1, vec(4, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        bool flag = false;
        if (dp[i-1][0] != INF && t[i-1] + p[i] <= t[i]) {
            dp[i][1] = dp[i-1][0] + p[i];
            flag = true;
        }

        if (dp[i-1][1] != INF) {
            if (t[i-1] + 2 * p[i-1] + p[i] <= t[i]) dp[i][1] = min(dp[i][1], dp[i-1][1] + p[i-1] + p[i]), flag = true;
            if (t[i-1] + 2 * abs(p[i] - p[i-1]) <= t[i]) dp[i][2] = min(dp[i][2], dp[i-1][1] + abs(p[i] - p[i-1])), flag = true;
        }

        if (dp[i-1][2] != INF) {
            if (t[i-1] + 3 * p[i-1] + p[i] <= t[i]) dp[i][1] = min(dp[i][1], dp[i-1][2] + p[i-1] + p[i]), flag = true;
            if (t[i-1] + 3 * abs(p[i-1] - p[i]) <= t[i]) dp[i][3] = min(dp[i][3], dp[i-1][2] + abs(p[i] - p[i-1])), flag = true;
        }

        if (dp[i-1][3] != INF) {
            if (t[i-1] + 4 * p[i-1] + p[i] <= t[i]) dp[i][1] = min(dp[i][1], dp[i-1][3] + p[i-1] + p[i]), flag = true;
        }

        if (!flag) {
            cout << "NG " << i << endl;
            return ;
        }
    }

    int ans = INF;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, dp[N][i] + p[N]);
    }

    cout << "OK " << ans << endl;
}

int main() {
    int N;
    while (cin >> N, N) solve(N);

    return 0;
}
