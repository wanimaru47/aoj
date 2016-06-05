#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N, M, A, B, C, T;

mat calc(mat &X, mat &Y) {
    mat ret(X.size(), vec(Y[0].size()));

    int row = X.size();
    int colume = Y[0].size();
    if (X[0].size() != Y.size()) return ret;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colume; j++) {
            for (int k = 0; k < X[i].size(); k++) {
                ret[i][j] += (X[i][k] * Y[k][j]) % M;
                ret[i][j] %= M;
            }
        }
    }

    return ret;
}

mat dfs(mat& X, int Times) {
    if (Times == 0) {
        mat ret(X.size(), vec(X[0].size()));
        for (int i = 0; i < X.size() && i < X[0].size(); i++) ret[i][i] = 1;
        return ret;
    }
    auto Y = dfs(X, Times / 2);
    auto YY = calc(Y, Y);
    if (Times % 2) {
        auto ret = calc(X, YY);
        return ret;
    } else {
        return YY;
    }
}

void solve() {
    mat d(N, vec(N));
    mat v(N, vec(1));
    for (auto& i : v) for (auto &j : i) cin >> j;
    for (int i = 0; i < N; i++) {
        d[i][i] = B;
        if (i + 1 < N) d[i+1][i] = A;
        if (i + 1 < N) d[i][i+1] = C;
    }

    auto d_start = dfs(d, T);
    auto ans = calc(d_start, v);

    for (int i = 0; i < N - 1; i++) cout << ans[i][0] << " "; cout << ans[N-1][0] << endl;
}

int main() {
    while (cin >> N >> M >> A >> B >> C >> T, A || B || C || N || M || T) solve();

    return 0;
}
