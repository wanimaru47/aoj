#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> P;

double calc(double x, double l, double _l) {
    double ret = x + sqrt((l + _l) * (l + _l) - (l - _l) * (l - _l));
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    for (auto &i : v) cin >> i;

    vector<double> p;
    p.push_back(0.);
    for (int i = 1; i < n; i++) {
        double x = 0.;
        for (int j = 0; j < i; j++) {
            x = max(x, calc(p[j], v[i], v[j]));
        }
        p.push_back(x);
    }

    double l = 0., r = 0.;
    for (int i = 0; i < n; i++) {
        l = min(l, p[i] - v[i]);
        r = max(r, p[i] + v[i]);
    }

    printf("%.9f\n", r - l);

    return 0;
}
