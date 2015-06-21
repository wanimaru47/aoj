#include <bits/stdc++.h>
using namespace std;

typedef vector<double> V;
typedef vector<V>   VV;
typedef vector<VV>  VVV;
typedef pair<int,int> P;
typedef pair<double,P> PP;

const int INF = 1 << 28;
const double dINF = 1e15;

int main ()
{
    int n, m, p, a, b;
    while (cin >> n >> m >> p >> a >> b, a + b + m + n + p) {
        VV v(m + 1, V(m + 1, INF));
        V t(n);
        vector<vector<pair<int,double> > > e(m + 1);
        for (int i = 0; i < n; i++) cin >> t[i]; 
        for (int i = 0; i <= m; i++) v[i][i] = 0;
        
        for (int i = 0; i < p; i++) {
            int x, y;
            double z;
            cin >> x >> y >> z;
            e[x].push_back(P(y, z));
            e[y].push_back(P(x, z));
            v[x][y] = v[y][x] = z;
        }


        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= m; k++) {
                    v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
                }
            }
        }

        // cout << "DBG > succes" << endl;  

        if (v[a][b] == INF) {
            cout << "Impossible" << endl;
        } else {
            priority_queue<PP, vector<PP>, greater<PP> > pq;
            vector<vector<double> > dp((1 << n), V(m + 1, INF));
            dp[0][a] = 0.;
            pq.push(PP(0, P(0, a)));
            double res = dINF; 

            while (pq.size()) {
                PP pp = pq.top(); pq.pop();
                double cost = pp.first;
                int used = pp.second.first;
                int now = pp.second.second;

                if (dp[used][now] < cost) continue;
                
                for (int i = 0; i < e[now].size(); i++) {
                    int next = e[now][i].first;
                    double dis = e[now][i].second;
                    for (int j = 0; j < n; j++) {
                        double cost_ = dis / t[j] + cost;
                        if (~used & (1 << j) && dp[used | (1 << j)][next] > cost_) {
                            dp[used | (1 << j)][next] = cost_;
                            pq.push(PP(cost_, P(used | (1 << j), next)));
                            if (next == b) res = min(res, cost_);
                        }
                    }
                }
            }
            if (res == dINF) cout << "Impossible" << endl;
            else printf("%.3f\n", res);
        }

    }

    return 0;
}
