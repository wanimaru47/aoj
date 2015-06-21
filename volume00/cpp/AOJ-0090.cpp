#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

typedef complex<double> P;

P rot (P x, P p, double ang) {
    ang = ang / 180.0 * M_PI;
    double p1 = p.real() - x.real();
    double p2 = p.imag() - x.imag();
    return P( p1 * cos(ang) - p2 * sin(ang) + x.real()
              , p1 * sin(ang) + p2 * cos(ang) + x.imag() );
}

int main () {
    int n;
    while (cin >> n, n) {
        vector<P> v(n);
        for (auto &i : v) {
            double x, y;
            char c;
            cin >> x >> c >> y;
            i = P(x,y);
        }

        int res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && abs(v[i] - v[j]) <= 2. + EPS) {
                    int count = 0;
                    P m = P(abs(v[i].real() + v[j].real()) / 2., abs(v[i].imag() + v[j].imag()) / 2.);
                    P p = m + (m - v[i]) / abs(m - v[i]) * sqrt(1. - pow(abs(m - v[i]), 2.));
                    p = rot(m, p, 90);
                    for (int k = 0; k < n; k++) {
                        if (abs(p - v[k]) <= 1. + EPS) count++;
                    }

                    res = max(res, count);
                }
            }
        }

        cout << res << endl;
    }
    
    return 0;
}
