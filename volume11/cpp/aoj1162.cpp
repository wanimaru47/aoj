#include <bits/stdc++.h>
using namespace std;

typedef edge { int to, cap, cost, rev; };

typedef vector<int> vec;
typedef vector<vec> mat;
typedef vector<edge> gvec;
typedef vector<gvec> gmat;

int N, M, C, S, T;

int main() {
    while (cin >> N >> M >> C >> A >> G, N || M || C || S || T) {
        gmat G(N + 1);
        vec dist(N + 1);
        vec prevv(N + 1);
        vec preve(N + 1);

        vec xvec(M), yvec(M), dvec(M), cvec(M);
        for (int i = 0; i < M; i++) {
            cin >> xvec[i] >> yvec[i] >> dvec[i] >> cvec[i];
        }

        mat q(C), r(C);
        for (int i = 0; i < C; i++) {
            int p; cin >> p;
            q[i].resize(p-1);
            r[i].resize(p);
        }

        mat c_cost(C);

        for (int i = 0; i < C; i++) {
            for (auto &j : q[i]) cin >> j;
            for (auto &j : r[i]) cin >> j;
            
            c_cost[i].resize(222);

            c_cost[i][0] = r[0];

            int l = 0;
            for (int j = 0; j < 222; j++) {
                if (l == q[i].size()) c_cost[i][j + 1] = c_cost[i][j];
                else {
                    if (q[i][l] > j) c_cost[i][j+1] = c_cost[i][j] + r[l];
                    if (q[i][l] == j + 1) l++;
                }
            }
        }

        auto add_edge = [&](int from, int to, int cap, int cost) {
            G[from].push_back((edge){to, cap, cost, G[to].size()});
            G[to].push_back((edge){from, 0, -cost, G[from].size() - 1});
        }

        for (int i = 0; i < M; i++) {
            add_edge(xvec[i], yvec[i], 1, c_cost[cvec[i]][dvec[i]]);
        }

        auto mim_cost_flow = [&](int s, int t, int f) {
            int res = 0;
            const int INF = 1 <<  28;

            while (f > 0) {
                dist.assign(N + 1, INF);
            }
        }
    }

    return 0;
}
