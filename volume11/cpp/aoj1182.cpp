#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

struct edge { int from, to, cap, cost, rev; };

int N, M, C, S, T;
const int INF  = 1 << 28;

int main() {
    while (cin >> N >> M >> C >> S >> T, N + M + C + S + T) {
        S--, T--;

        vector<mat> ccost(C, mat(N, vec(N, INF)));
        for (int c = 0; c < C; c++)
            for (int i = 0; i < N; i++) ccost[c][i][i] = 0;

        for (int i = 0; i < M; i++) {
            int x, y, d, c; cin >> x >> y >> d >> c;
            x--, y--, c--;
            ccost[c][x][y] = ccost[c][y][x] = min(ccost[c][y][x], d);
        }

        for (auto &c : ccost)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    for (int k = 0; k < N; k++)
                        c[j][k] = min(c[j][k], c[j][i] + c[i][k]);

        mat lvec(C), rvec(C);
        for (int i = 0; i < C; i++) {
            int n; cin >> n;
            lvec[i].resize(n-1);
            rvec[i].resize(n);
        }

        mat dcost(C, vec(100000));
        for (int i = 0; i < C; i++) {
            for (auto &j : lvec[i]) cin >> j;
            for (auto &j : rvec[i]) cin >> j;

            for (int j = 0, k = 0; j < 100000; j++) {
                if (k == lvec[i].size()) dcost[i][j+1] = dcost[i][j] + rvec[i][k];
                else {
                    dcost[i][j+1] = dcost[i][j] + rvec[i][k];
                    if (j + 1 == lvec[i][k]) k++;
                }
            }
        }

        mat G(N, vec(N, INF));
        for (int c = 0; c < C; c++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (ccost[c][i][j] != INF) 
                        G[i][j] = min(G[i][j], dcost[c][ccost[c][i][j]]);
                }
            }
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) 
                for (int k = 0; k < N; k++) G[j][k] = min(G[j][k], G[j][i] + G[i][k]);

        cout << (G[S][T] == INF ? -1 : G[S][T]) << endl;
    }
    
    return 0;
}
