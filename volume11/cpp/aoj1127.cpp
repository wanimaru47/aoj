#include <bits/stdc++.h>
using namespace std;

typedef pair<double,int> P;

const double INF = 1e10;

int main ()
{
    int n;
    while (cin >> n, n) {
        vector<double> x(n), y(n), z(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> z[i] >> r[i];
        }

        vector<vector<double> > dis(n, vector<double>(n, INF));
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                double tdis = pow(x[i] - x[j], 2.0) + pow(y[i] - y[j], 2.0) + pow(z[i] - z[j], 2.0);
                tdis = sqrt(tdis) - r[i] - r[j];
                if (tdis < 0.0) tdis = 0.0;
                dis[i][j] = dis[j][i] = tdis;
            }
        }

        priority_queue<P, vector<P>, greater<P> > que;
        vector<bool> used(n, false);
        double res = 0.0;
        for (int i = 0; i < n; i++) {
            que.push(P(dis[0][i], i));
        }
        used[0] = true;
        while (que.size()) {
            P p = que.top(); que.pop();

            if (used[p.second]) continue;
            res += p.first;
            used[p.second] = true;
            for (int i = 0; i < n; i++) {
                que.push(P(dis[p.second][i], i));
            }
        }

        printf("%.3f\n", res);
    }

    return 0;
}
