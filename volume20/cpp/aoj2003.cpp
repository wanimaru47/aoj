#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

typedef complex<double> P;
typedef vector<int> vec;
typedef vector<vec> mat;

double cross (P a, P b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

bool is_intersected_ls(P a1, P a2, P b1, P b2) {
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < - EPS ) &&
        ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < - EPS );
}

P intersection_l(P a1, P a2, P b1, P b2) {
    P a = a2 - a1; P b = b2 - b1;
    return a1 + a * cross(b, b1-a1) / cross(b, a);
}

void solve() {
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    int N;
    cin >> N;

    vec sx(N), sy(N), tx(N), ty(N), o(N), l(N);
    for (int i = 0; i < N; i++) {
        cin >> sx[i] >> sy[i] >> tx[i] >> ty[i] >> o[i] >> l[i];
    }

    P ap(ax, ay);
    P bp(bx, by);
    vec crossed_idx;
    for (int i = 0; i < N; i++) {
        P sp(sx[i], sy[i]);
        P tp(tx[i], ty[i]);
        if (is_intersected_ls(ap, bp, sp, tp)) crossed_idx.push_back(i);
    }

    vector<pair<double,int> > points;
    for (int i = 0, len = crossed_idx.size(); i < len; i++) {
        int c = crossed_idx[i];
        P sp(sx[c], sy[c]);
        P tp(tx[c], ty[c]);
        P point = intersection_l(ap, bp, sp, tp);
        double dist = abs(point - ap);
        points.push_back(pair<double,int>(dist, c));
    }

    sort(points.begin(), points.end());

    int fst;
    bool is_over;
    if (points.size()) {
        fst = points[0].second;
        if (o[fst]) {
            if (l[fst]) is_over = true;
            else is_over = false;
        } else {
            if (!l[fst]) is_over = true;
            else is_over = false;
        }
    }

    int ans = 0;
    for (int i = 0, len = points.size(); i < len; i++) {
        int now = points[i].second;
        if (o[now]) {
            if (l[now] != is_over) {
                ans++;
                is_over = !is_over;
            }
        } else {
            if (l[now] == is_over) {
                ans++;
                is_over = !is_over;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    int N; cin>> N;
    while (N--) solve();

    return 0;
}
