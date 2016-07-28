#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

const int INF = 1 << 28;
int N, M, R;

void solve() {
    mat dps(N, vec(N, INF));
    mat dpl(N, vec(N, INF));
    for (int i = 0; i < M; i++) {
        int x, y, t;
        char c;
        cin >> x >> y >> t >> c;
        x--, y--;
        if (c == 'L') dpl[x][y] = dpl[y][x] = min(dpl[x][y], t);
        if (c == 'S') dps[x][y] = dps[y][x] = min(dps[x][y], t);
    }

    for (int i = 0; i < N; i++) dpl[i][i] = dps[i][i] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dpl[j][k] = min(dpl[j][k], dpl[j][i] + dpl[i][k]);
                dps[j][k] = min(dps[j][k], dps[j][i] + dps[i][k]);
            }
        }
    }

    cin >> R;
    vec z(R);
    for (auto& i : z) cin >> i, i--;

    mat dp(R, vec(N, INF));
    dp[0][z[0]] = 0;
    for (int i = 0; i < R-1; i++) {
        for (int j = 0; j < N; j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+dpl[z[i]][z[i+1]]);
            for (int k = 0; k < N; k++) {
                dp[i+1][k] = min(dp[i+1][k],
                                 dp[i][j]+dpl[z[i]][j]+dps[j][k]+dpl[k][z[i+1]]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < N; i++) {
        ans = min(ans, dp[R-1][i]);
    }

    cout << ans << endl;
}

int main() {
    while (cin >> N >> M, N || M) solve();

    return 0;
}
