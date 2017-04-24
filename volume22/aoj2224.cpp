#include <bits/stdc++.h>
using namespace std;

struct UniFi {
    vector<int> par;
    UniFi (int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
    };

    int is_par(int x) {
        if (x == par[x]) return x;
        else return (par[x] = is_par(par[x]));
    }

    void unite(int x, int y) {
        x = is_par(x);
        y = is_par(y);

        if (x < y) par[y] = x;
        else par[x] = y;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<double> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    vector<int> p(M), q(M);
    vector<pair<double,int> > len(M);
    for (int i = 0; i < M; i++) {
        cin >> p[i] >> q[i];
        p[i]--, q[i]--;
        int a = p[i];
        int b = q[i];
        len[i] = pair<double,int>(-sqrt(pow(x[a] - x[b], 2.) + pow(y[a] - y[b], 2.)), i);
    }
    sort(len.begin(),len.end());

    UniFi ff(N);
    double ans = 0.0;
    for (int i = 0; i < M; i++) {
        int a = p[len[i].second];
        int b = q[len[i].second];
        if (ff.is_par(a) != ff.is_par(b)) {
            ff.unite(a, b);
        } else {
            ans -= len[i].first;
        }
    }

    printf("%.8f\n", ans);

    return 0;
}
