#include <bits/stdc++.h>
using namespace std;

typedef complex<double> P;

int main() {
    int N;
    while (cin >> N, N != -1) {
        P p = P(1., 1.);
        for (int i = 2; i < N; i++) {
            P e = p / abs(p);
            double SIN = sin(0.5 * M_PI);
            double COS = cos(0.5 * M_PI);
            e = P(e.real() * COS - e.imag() * SIN, e.real() * SIN + e.imag() * COS);
            p += e;
        }

        cout << p.real() << endl;
        cout << p.imag() << endl;
    }

    return 0;
}
