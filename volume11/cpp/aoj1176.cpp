#include <bits/stdc++.h>
using namespace std;

const int INF  = 1 << 28;

typedef pair<i+ sum, 1);

    vector<int> H(n + 1);
    vector<int> W(m + 1);

    for (int i = wl; i < wr; i++) {
        int lsum = 0;
        for (int j = ht; j < hb; j++ ) {
            lsum += v[j][i];
        }

        W[i + 1] = lsum + W[i];
    }

    for (int i = ht; i < hb; i++) {
        int lsum = 0;
        for (int j = wl; j < wr; j++ ) {
            lsum += v[i][j];
        }

        H[i + 1] = lsum + H[i];
    }

    
    for (int i = wl + 1; i < wr; i++) {
        P t1 = dfs (v, W[wr] - W[i], i, wr, ht, hb);
        P t2 = dfs (v, W[i], wl, i, ht, hb);

        if (t1 != P(-1,-1) && t2 != P(-1,-1)) {
            P t(min(t1.first, t2.first), t1.second + t2.second);
            
            if (res.second <= t.second) {
                if (t.first == res.first) res.second = max(t.first, res.first);
                else res = t;
            }
        }
    }
    for (int i = ht + 1; i < hb; i++) {
        P t1 = dfs (v, H[i], wl, wr, ht, i);
        P t2 = dfs (v, H[hb] - H[i], wl, wr, i, hb);

        if (t1 != P(-1,-1) && t2 != P(-1,-1)) {
            P t(min(t1.first, t2.first), t1.second + t2.second);

            if (res.second <= t.second) {
                if (t.first == res.first) res.second = max(t.first, res.first);
                else res = t;
            }
        }
    }

    return res;
}

int main () {
    while ( cin >> n >> m >> c, n + m + c) {
        int sum = 0;
        vector<vector<int> > v(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
                total += v[i][j];
            }
        }

        cout << "Start " << endl;

        int wl = 0, wr = m, ht = 0, tb = n;
        P res = dfs(v, total, wl, wr, ht, tb);


        cout << res.second << " " << res.first << endl;
    }
    
    return 0;
}
