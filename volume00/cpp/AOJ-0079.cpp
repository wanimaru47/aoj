#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <complex>
#include <vector>
#include <iomanip>
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

double triangle (P a, P b, P c) {
    double x = abs(a-b), y = abs(b-c), z = abs(c-a);
    double Z = (x + y + z) / 2.0;
    return sqrt(Z * (Z - x) * (Z - y) * (Z - z));
}

double area_size (vector<P> v) {
    if (v.size() < 3) return 0;
    double res = 0.0;
    for (int i = 1; i < v.size() - 1; i++) {
        res += triangle(v[0], v[i], v[i+1]);
    }
    return res;
}

int main ()
{
    vector<P> p;
    double a,b;
    while (scanf("%lf,%lf", &a, &b) != EOF) {
        p.push_back(P(a,b));
    }

    auto v = convex_hull(p);
    printf("%.6f\n" , area_size(v));

    return 0;
}
