#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

const int INF = 1 << 28;
int N, M, L, K, A, H;

void solve() {
    vec lf(L); for (auto &i : lf) cin >> i;
    lf.push_back(A);
    lf.push_back(H);

    mat wfroid(N, vec(N, INF));
    for (int i = 0; i < N; i++) wfroid[i][i] = 0;
    for (int i = 0; i < K; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        wfroid[x][y] = wfroid[y][x] = z;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) wfroid[j][k] = min(wfroid[j][k], wfroid[j][i] + wfroid[i][k]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (wfroid[i][j] > M) wfroid[i][j] = INF;

    for (int i = 0; i < lf.size(); i++)
        for (int j = 0; j < lf.size(); j++)
            for (int k = 0; k < lf.size(); k++)
                wfroid[lf[j]][lf[k]] = min(wfroid[lf[j]][lf[k]], wfroid[lf[j]][lf[i]] + wfroid[lf[i]][lf[k]]);

    if (wfroid[A][H] == INF) cout << "Help!" << endl;
    else cout << wfroid[A][H] + max(0, (wfroid[A][H] - M)) << endl;
}

int main() {
    while (cin >> N >> M >> L >> K >> A >> H, N || M || L || K || A || H) solve();

    return 0;
}
