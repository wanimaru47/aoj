#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

typedef complex<double> P;

int N;
vector<double> X, Y, L;

bool check(int n, int m, int p, double h) {
    double H = h * h;
    double l1 = L[n] * L[n] - H;
    double l2 = L[m] * L[m] - H;
    double l3 = L[p] * L[p] - H;

    double s[] = {l1, l2, l3};
    int v[] = {n, m, p};

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            int k = 3 - i - j;
            P p1 = P(X[v[i]], Y[v[i]]);
            P p2 = P(X[v[j]], Y[v[j]]);
            P p3 = P(X[v[k]], Y[v[k]]);

            auto dist0 = abs(p1 - p2);

            if ((dist0 - sqrt(s[i]) - sqrt(s[j])) >= 0) return false;

            if (dist0 <= sqrt(s[i]) + sqrt(s[j])) {
                if (s[i] < s[j]){
                    auto dist1 = abs(p1 - p3);
                    if (dist1 <= (sqrt(s[k]) + sqrt(s[i]))) return true;
                } else if (dist0 <= sqrt(s[j])) {
                    auto dist1 = abs(p1 - p3);
                    if (sqrt(dist1) <= (sqrt(s[k]) + sqrt(s[j]))) return true;
                }
            }

            double C1 = (X[v[i]] - X[v[j]]) / (Y[v[j]] - Y[v[i]]);
            double C2 = (s[i] - s[j] - (X[v[i]] * X[v[i]] - X[v[j]] * X[v[j]])
                         - (Y[v[i]] * Y[v[i]] - Y[v[j]] * Y[v[j]])) / 2. / (2 * (Y[v[j]] - Y[v[i]]));
            double C3 = 1. + C1 * C1;
            double C4 = 2. * C1 * (C2 - Y[v[i]]) - 2 * X[v[i]];
            double C5 = X[v[i]] * X[v[i]] + (C2 - Y[v[i]]) * (C2 - Y[v[i]]) - s[i];
            double X1 = (- C4 + sqrt(C4 * C4 - 4 * C3 * C5)) / (2. * C3);
            double X2 = (- C4 - sqrt(C4 * C4 - 4 * C3 * C5)) / (2. * C3);
            double Y1 = C1 * X1 + C2;
            double Y2 = C1 * X2 + C2;

            if (abs(X1 - X2) < EPS && abs(Y1 - Y2) < EPS) {
                double dist1 = (X1 - X[v[k]]) * (X1 - X[v[k]]) + (Y1 - Y[v[k]]) * (Y1 - Y[v[k]]);
                if (abs(dist1 - s[k]) < EPS) return true;
            }

            double dist1 = (X1 - X[v[k]]) * (X1 - X[v[k]]) + (Y1 - Y[v[k]]) * (Y1 - Y[v[k]]);
            double dist2 = (X2 - X[v[k]]) * (X2 - X[v[k]]) + (Y2 - Y[v[k]]) * (Y2 - Y[v[k]]);

            if (dist1 <= s[k] || dist2 <= s[k]) return true;
        }
    }

    return false;
}

void solve() {
    double res = 1LL << 28;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int k = j; k < N; k++) {
                double l = 1., r = res;
                for (int loop = 0; loop < 100; loop++) {
                    if (check(i, j, k, (l + r) / 2.)) {
                        l = (l + r) / 2.;
                    } else {
                        r = (l + r) / 2.;
                    }
                }
                res = min(res, l);
            }
        }
    }

    printf("%.10f\n", res);
}

int main() {
    while (cin >> N, N) {
        X.resize(N), Y.resize(N), L.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> X[i] >> Y[i] >> L[i];
        }

        if (N == 1) cout << L[0] << endl;
        else {
            if (N == 2) {
                N++;
                X.push_back(X[0]);
                Y.push_back(Y[0]);
                L.push_back(L[0]);
            }
            solve();
        }
    }

    return 0;
}
