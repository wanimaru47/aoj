#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> d(M);
    vector<int> idx(N, -1);
    for (int i = 0; i < M; i++) {
        cin >> d[i];
        idx[d[i]-1] = i;
    }

    vector<vector<int> > v(N, vector<int>(K));
    for (auto& i : v) for (auto& j : i) cin >> j;

    vector<int> dp(1 << M, 1 << 28);
    dp[0] = 0;


    vector<vector<int> > nx(K, vector<int>(1<<M));
    for (int i = 1; i < (1<<M); i++) {
        for (int j = 0; j < K; j++) {
            int x = 0;
            for (int k = 0; k < M; k++) {
                auto t = idx[v[d[k]-1][j]-1];
                if ((i & (1<<k)) && t >= 0)
                    x |= (1<<t);
            }
            nx[j][i] = x;
            dp[i] = min(dp[i], dp[x] + 1);
        }
    }

    for (int g = 0; g < 2 * M; g++) {
        for (int i = 1; i < (1<<M); i++) {
            for (int j = 0; j < K; j++) {
                int x = nx[j][i];
                dp[i] = min(dp[i], dp[x] + 1);
            }
        }
    }

    cout << dp[(1<<M)-1] << endl;

    return 0;
}
