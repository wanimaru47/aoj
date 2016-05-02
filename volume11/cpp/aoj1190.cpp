#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

typedef complex<double> P;

int N;
vector<double> X, Y, L;

bool check(int n, int m, int p, double h) {
    P p1 = P(X[n], Y[n]);
    P p2 = P(X[m], Y[m]);
    P p3 = P(X[p], Y[p]);
    double r1 = sqrt(L[n] * L[n] - h * h);
    double r2 = sqrt(L[m] * L[m] - h * h);
    double r3 = sqrt(L[p] * L[p] - h * h);

    if (abs(p1 - p2) > r1 + r2) return false;
    if (abs(p1 - p2) <= abs(r2 - r1)) {
        if (r1 <= r2 && abs(p1 - p3) <= r1 + r3) {
            return true;
        }
        else if (r2 <= r1 && abs(p2 - p3) <= r2 + r3) {
            return true;
        }
        else return false;
    }

    if (abs(p1 - p2) == r1 + r2) {
        P p = p1 + (r1 / (r1 + r2)) * (p2 - p1);
        if (abs(p - p3) <= r3) return true;
        return false;
    } else if (abs(r1 - r2) < abs(p1 - p2) && abs(p1 - p2) < r1 + r2) {
        double A = 2. * (p2.real() - p1.real());
        double B = 2. * (p2.imag() - p1.imag());
        double C = r1 * r1 - r2 * r2 - (p1.real() * p1.real() - p2.real() * p2.real()) - (p1.imag() * p1.imag() - p2.imag() * p2.imag());
        double X1, X2, Y1, Y2;
        double Ad, Bd, Cd;
        if (B == 0) {
            X1 = X2 = C / A;
            Y1 = p1.imag() - sqrt(r1 * r1 - (X1 - p1.real()) * (X1 - p1.real()));
            Y2 = p1.imag() + sqrt(r1 * r1 - (X1 - p1.real()) * (X1 - p1.real()));
        } else if (A == 0) {
            Y1 = Y2 = C / B;
            X1 = p1.real() - sqrt(r1 * r1 - (Y1 - p1.imag()) * (Y1 - p1.imag()));
            X2 = p1.real() + sqrt(r1 * r1 - (Y1 - p1.imag()) * (Y1 - p1.imag()));
        } else {
            Ad = 1. + (A / B) * (A / B);
            Bd = -2 * p1.real() - 2 * (A / B) * (C / B - p1.imag());
            Cd = (C / B - p1.imag()) * (C / B - p1.imag()) - r1 * r1 + p1.real() * p1.real();
            X1 = (- Bd + sqrt(Bd * Bd - 4. * Ad * Cd)) / (2. * Ad);
            X2 = (- Bd - sqrt(Bd * Bd - 4. * Ad * Cd)) / (2. * Ad);
            Y1 = (- A / B) * X1 + (C / B);
            Y2 = (- A / B) * X2 + (C / B);
        }
        P p1d = P(X1, Y1);
        P p2d = P(X2, Y2);

        if (abs(p1d - p3) <= r3) return true;
        if (abs(p2d - p3) <= r3) return true;
    }

    return false;
}

void solve() {
    double res_r = 1LL << 28;
    double res_l = 1LL << 28;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int k = j; k < N; k++) {
                int v[] = {i, j, k};
                double l = 0., r = min(L[i], min(L[j], L[k]));
                for (int loop = 0; loop < 100; loop++) {
                    bool flag = false;
                    for (int I = 0; I < 3; I++) {
                        for (int J = I + 1; J < 3; J++) {
                            int K = 3 - J - I;
                            flag |= check(v[I], v[J], v[K], (l + r) / 2.);
                        }
                    }
                    if (flag) {
                        l = (l + r) / 2.;
                    } else {
                        r = (l + r) / 2.;
                    }
                    res_r = min(res_r, r);
                    res_l = min(res_l, l);
                }
            }
        }
    }
    printf("%.10f\n", res_r);
}

int main() {
    while (cin >> N, N) {
        X.resize(N), Y.resize(N), L.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> X[i] >> Y[i] >> L[i];
        }

        solve();
    }

    return 0;
}
