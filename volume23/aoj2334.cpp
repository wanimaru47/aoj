#include <bits/stdc++.h>
#define EPS 1e-10
using namespace std;

typedef complex<double> P;

double cross (P a, P b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

bool is_intersected_ls(P a1, P a2, P b1, P b2) {
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < - EPS ) &&
        ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < - EPS );
}

double calc(vector<vector<double> > v) {
    vector<double> ret(v.size(), 1e10);
    ret[0] = 0.0;
    priority_queue<pair<double,int>, vector<pair<double,int> >, greater<pair<double,int> > > que;
    que.push(make_pair(0.0, 0));
    while (que.size()) {
        auto p = que.top(); que.pop();
        auto dist = p.first;
        auto now = p.second;
        for (int i = 0; i < v.size(); i++) {
            if (v[now][i] != 1e5) {
                auto now_dist = dist + v[now][i];
                auto next = i;
                if (now_dist < ret[i]) {
                    ret[i] = now_dist;
                    que.push(make_pair(now_dist, i));
                }
            }
        }
    }

    return ret[1];
}

int main() {
    int A, B;
    cin >> A >> B;
    vector<double> ax(A), ay(A), bx(B), by(B);
    for (int i = 0; i < A; i++) cin >> ax[i] >> ay[i];
    for (int i = 0; i < B; i++) cin >> bx[i] >> by[i];

    P a0 = P(ax[0], ay[0]);
    P a1 = P(ax[1], ay[1]);
    P b0 = P(bx[0], by[0]);
    P b1 = P(bx[1], by[1]);

    double ans = 1e8;
    vector<vector<double> > va(B, vector<double>(B, 1e5));
    for (int i = 0; i < B; i++) {
        for (int j = i + 1; j < B; j++) {
            P x(bx[i], by[i]), y(bx[j], by[j]);
            if (!is_intersected_ls(a0, a1, x, y)) {
                va[i][j] = va[j][i] = abs(x - y);
            }
        }
    }
    ans = min(ans, calc(va) + abs(a0 - a1));
    vector<vector<double> > vb(A, vector<double>(A, 1e5));
    for (int i = 0; i < A; i++) {
        for (int j = i + 1; j < A; j++) {
            P x(ax[i], ay[i]), y(ax[j], ay[j]);
            if (!is_intersected_ls(b0, b1, x, y)) {
                vb[i][j] = vb[j][i] = abs(x - y);
            }
        }
    }
    ans = min(ans, calc(vb) + abs(b0 - b1));

    if (ans == 1e8) cout << -1 << endl;
    else printf("%.10f\n", ans);

    return 0;
}
