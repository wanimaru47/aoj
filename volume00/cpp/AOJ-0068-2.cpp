#include <iostream>
#include <cstdio>
#include <complex>
#include <vector>
#include <algorithm>
#define EPS 1e-10
#define EQ(a,b) (abs(a - b) < EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))

using namespace std;

typedef complex<double> P;

double cross (P a, P b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

bool cmp_x (const P& p, const P& q) {
    if (p.real() != q.real()) return p.real() < q.real();
    else return p.imag() < q.imag();
}

vector<P> convex_hull (vector<P> ps) {
    int n = ps.size(), k = 0;
    vector<P> qs (n * 2); 
    sort(ps.begin(), ps.end(), cmp_x);
    for (int i = 0; i < n; i++) {
        while (k > 1 && cross (qs[k-1] - qs[k-2], ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t && cross (qs[k-1] - qs[k-2], ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}

int main ()
{
    int n;
    while (cin >> n, n) {
        vector<P> ps;
        for (int i = 0; i < n; i++) {
            double a, b;
            scanf("%lf,%lf", &a, &b);
            ps.push_back(P(a,b));
        }

        vector<P> qs = convex_hull (ps);
        cout << (ps.size() - qs.size()) << endl;
    }

    return 0;
}
