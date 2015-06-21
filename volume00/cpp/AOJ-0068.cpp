// なんか動かなかった


#include <iostream>
#include <queue>
#include <complex>
#include <algorithm>
#define EPS 1e-10
#define EQ(a,b) (abs(a-b) < EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))
using namespace std;

typedef complex<double> P;

double dot (P a, P b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}

bool cmp_x (const P& p, const P& q) {
    if (p.real() != q.real()) return p.real() < q.real();
    else return p.imag() < q.imag();
}

vector<P> convex_hull (vector<P> ps) {
    sort(ps.begin(), ps.end(), cmp_x);
    int k = 0, n = ps.size();
    vector<P> qs(n * 2);
    for (auto& i : ps) {
        while (k > 1 && dot (qs[k-1] - qs[k-2], i - qs[k-1]) <= 0) k--;
        qs[k++] = i;
    }
    for (int i = n -2, t = k; i >= 0; i--) {
        while (k > t && dot (qs[k-1] - qs[k-2], ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}

int main ()
{
    int n;
    while (cin >> n, n > 0) {
        vector<P> ps;
        while (n--) {
            double a, b;
            cin >> a >> b;
            ps.push_back(P(a,b));
        }
        n = ps.size();

        vector<P> qs = convex_hull (ps);
        double res = 0;
        for (int i = 0; i < qs.size(); i++) {
            for (int j = 0; j < i; j++) {
                res = max(res, abs(qs[i]-qs[j]));
            }
        }
        cout << (int)res << endl;
    }

    return 0;
}
