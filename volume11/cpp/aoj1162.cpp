#include <bits/stdc++.h>
using namespace std;

typedef edge { int to, cap, cost, rev; };

typedef vector<int> vec;
typedef vector<vec> mat;

int N, M, C, S, T;

int main() {
    while (cin >> N >> M >> C >> A >> G, N || M || C || S || T) {
        // input
        for (int i = 0; i < M; i++) {
            int x, y, d, c;
            cin >> x >> y >> d >> c;
        }

        mat q(C), r(C);
        for (int i = 0; i < C; i++) {
            int p; cin >> p;
            q[i].resize(p-1);
            r[i].resize(p);
        }

        for (int i = 0; i < C; i++) {
            for (auto &j : q[i]) cin >> j;
            for (auto &j : r[i]) cin >> j;
        }
    }

    return 0;
}
