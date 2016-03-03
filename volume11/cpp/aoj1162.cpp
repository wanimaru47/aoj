#include <bits/stdc++.h>
using namespace std;

struct edge { int to, cap, cost, rev, cmp; };

typedef vector<int> vec;
typedef vector<vec> mat;
typedef vector<edge> gvec;
typedef vector<gvec> gmat;

int N, M, C, S, T;
const int INF = 1 <<  28;

int main() {
    while (cin >> N >> M >> C >> S >> T, N || M || C || S || T) {
        gmat G(N + 1);
        vec dist(N + 1);
        vec prevv(N + 1);
        vec preve(N + 1);
        mat cmp_idx(C);
        S--;
        T--;

        vec xvec(M), yvec(M), dvec(M), cvec(M);
        for (int i = 0; i < M; i++) {
            cin >> xvec[i] >> yvec[i] >> dvec[i] >> cvec[i];
            xvec[i]--;
            yvec[i]--;
            cvec[i]--;
            cmp_idx[cvec[i]].push_back(i);
        }

        mat q(C), r(C);
        for (int i = 0; i < C; i++) {
            int p; cin >> p;
            q[i].resize(p-1);
            r[i].resize(p);
        }

        mat c_cost(C, vec(222,0));

        for (int i = 0; i < C; i++) {
            for (auto &j : q[i]) cin >> j;
            for (auto &j : r[i]) cin >> j;

            c_cost[i][0] = 0;

            int l = 0;
            for (int j = 0; j < 222; j++) {
                if (l == q[i].size()) c_cost[i][j + 1] = c_cost[i][j] + r[i][l];
                else {
                    if (q[i][l] > j) c_cost[i][j+1] = c_cost[i][j] + r[i][l];
                    if (q[i][l] == j + 1) l++;
                }
            }
        }

        // cout << "###########################################" << endl;
        // for (auto i : c_cost) {
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        // cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

        auto add_edge = [&](int from, int to, int cap, int cost, int cmp) {
            G[from].push_back((edge){to, cap, cost, (int)(G[to].size()), cmp});
            G[to].push_back((edge){from, cap, cost, (int)(G[from].size()) - 1, cmp});
        };

        vector<mat> CC(C);

        for (int i = 0; i < C; i++) {
            CC[i].assign(N+1, vec(N+1, INF));

            for (auto j : cmp_idx[i]) {
                CC[i][xvec[j]][yvec[j]] = CC[i][yvec[j]][xvec[j]] = dvec[j];
            }

            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    for (int l = 0; l < N; l++) {
                        CC[i][k][l] = min(CC[i][k][l], CC[i][k][j] + CC[i][j][l]);
                    }
                }
            }

            for (int j = 0; j < N; j++) {
                for (int k = j; k < N; k++) {
                    cout << j << " " << k << " ";
                    if ((int)CC[i][j][k] < INF) {
                        cout << "OK";
                        add_edge(j, k, 1, c_cost[i][(int)CC[i][j][k]], i);
                    }
                    cout << endl;
                }
            }
        }


        // cout << "OK" << endl;
        // for (int i = 0; i < M; i++) {
        //     add_edge(xvec[i], yvec[i], 1, c_cost[cvec[i]][dvec[i]]);
        // }
        // cout << "KK" << endl;

        auto min_cost_flow = [&](int s, int t, int f) {
            int res = 0;

            while (f > 0) {
                dist.assign(N + 1, INF);
                dist[s] = 0;
                bool update = true;

                while (update) {
                    update = false;
                    for (int v = 0;  v < N; v++) {
                        if (dist[v] == INF) continue;

                        for (int i = 0; i < G[v].size(); i++) {
                            edge &e = G[v][i];
                            if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                                dist[e.to] = dist[v] + e.cost;
                                prevv[e.to] = v;
                                preve[e.to] = i;
                                update = true;
                                // cout << "Update: " << v << " to " << e.to << " , dist = " << dist[e.to] << endl;
                            }
                        }
                    }
                }

                if (dist[t] == INF) return -1;

                int d = f;
                for (int  v = t; v != s; v = prevv[v]) {
                    d = min(d, G[prevv[v]][preve[v]].cap);
                }

                f -= d;
                res += d * dist[t];
                for (int v = t; v != s; v = prevv[v]) {
                    edge &e = G[prevv[v]][preve[v]];
                    e.cap -= d;
                    G[v][e.rev].cap += d;
                }

                // cout << "flow: " << d << endl;
            }

            return res;
        };

        cout << min_cost_flow(S, T, 1) << endl;
    }

    return 0;
}
