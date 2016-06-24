#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, L;
    cin >> N >> M >> L;
    vector<double> P(N), T(N), V(N);
    for (int i = 0; i < N; i++)
        cin >> P[i] >> T[i] >> V[i];
    for (int i = 0; i < N; i++)
        P[i] = P[i] / 100.;

    vector<vector<double> > times(N, vector<double>(M + 1)), prob(N, vector<double>(M + 1));
    for (int i = 0; i < N; i++)
        times[i][0] = (double)L / V[i];

    vector<vector<long long int> > comb(M + 1, vector<long long int>(M + 1));
    for (auto& i : comb) i[0] = 1LL;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= M; j++) {
            long long int up = comb[i-1][j];
            long long int left = comb[i-1][j-1];
            comb[i][j] = up + left;
        }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (j > 0) times[i][j] = times[i][j-1] + T[i];
            prob[i][j] = pow(P[i], j) * pow(1.000 - P[i], M - j) * comb[M][j];
        }
    }

    for (int i = 0; i < N; i++) {
        double ans = 0.0000;
        for (int j = 0; j <= M; j++) {
            double tmp = 1.0000;
            for (int k = 0; k < N; k++) {
                if (k == i) continue;
                double sum = 0.0000;
                for (int l = 0; l <= M; l++) {
                    if (times[i][j] < times[k][l]) sum += prob[k][l];
                }
                tmp *= sum;
            }
            ans += prob[i][j] * tmp;
        }
        printf("%.10f\n", ans);
    }


    return 0;
}
