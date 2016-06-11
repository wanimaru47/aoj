#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

const int INF = 1 << 28;

int main() {
    int N, M;
    cin >> N >> M;

    vector<P> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());
    int len = sqrt(N);
    vector<vector<P> > m((N + len - 1) / len), n((N + len - 1) / len);

    for (int i = 0; i < N; i++) {
        m[i / len].push_back(P(v[i].second, v[i].first));
        n[i / len].push_back(v[i]);
    }

    for (auto& i : m) {
        sort(i.begin(), i.end());
    }

    while (M--) {
        int sx, sy, gx, gy;
        cin >> sx >> sy >> gx >> gy;

        int ans = 0;
        for (int i = 0; i < m.size(); i++) {
            int n_first = n[i][0].first;
            int n_last = n[i][n[i].size()-1].first;
            if ((sx <= n_first && n_first <= gx) && (sx <= n_last && n_last <= gx)) {
                int low = lower_bound(m[i].begin(), m[i].end(), P(sy, -INF)) - m[i].begin();
                int up = upper_bound(m[i].begin(), m[i].end(), P(gy, INF)) - m[i].begin();
                ans += up - low;
            } else {
                if ((n_first <= sx && sx <= n_last) || (n_first <= gx && gx <= n_last)) {
                    int low = lower_bound(n[i].begin(), n[i].end(), P(sx,sy)) - n[i].begin();
                    int up = upper_bound(n[i].begin(), n[i].end(), P(gx,gy)) - n[i].begin();
                    for (low; low <= up; low++) {
                        if (
                            sx <= n[i][low].first && n[i][low].first <= gx
                            && sy <= n[i][low].second && n[i][low].second <= gy
                            ) ans++;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
