#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> PP;

int N, M, H, K;

int main() {
    while (cin >> N >> M >> H >> K, N || M || H || K) {
        vector<vector<int>> v(N), c(N), h(N), r(N);
        for (int i = 0; i < M; i++) {
            int x, y, z, w, u;
            cin >> x >> y >> z >> w >> u;
            x--, y--, u--;
            v[x].push_back(y);
            v[y].push_back(x);
            c[x].push_back(z);
            c[y].push_back(z);
            h[x].push_back(w);
            h[y].push_back(w);
            r[x].push_back(u);
            r[y].push_back(u);
        }

        int S, T, Q;
        cin >> S >> T >> Q;
        S--, T--;
        vector<int> price(Q);
        vector<int> cam(Q);

        for (int i = 0; i < Q; i++) {
            int l;
            cin >> l >> price[i];
            for (int j = 0; j < l; j++) {
                int x;
                cin >> x;
                cam[i] |= (1 << (x - 1));
            }
        }

        const int INF = 1 << 27;
        vector<int> dp_p(1 << K, INF);
        dp_p[0] = 0;
        for (int i = 0; i < 1 << K; i++) {
            for (int j = 0; j < Q; j++) {
                if ((i | cam[j]) < (1 << K))
                    dp_p[i|cam[j]] = min(dp_p[i|cam[j]], dp_p[i] + price[j]);
            }
        }

        int ans = INF;
        for (int i = 0; i < 1 << K; i++) {
            if (dp_p[i] == INF) continue;

            vector<vector<int>> dp(N+1, vector<int>(H+1, INF));
            dp[S][0] = 0;

            priority_queue<PP, vector<PP>, greater<PP>> que;
            que.push(PP(0, P(0, S)));

            while (que.size()) {
                PP p = que.top(); que.pop();
                int cost = p.first;
                int now = p.second.second;
                int hour = p.second.first;

                if (dp[now][hour] < cost) continue;

                for (int j = 0; j < v[now].size(); j++) {
                    int next = v[now][j];
                    int ncost = cost;
                    if ((i & (1 << r[now][j])) == 0) ncost += c[now][j];
                    int nhour = hour + h[now][j];

                    if (nhour <= H && dp[next][nhour] > ncost) {
                        dp[next][nhour] = min(dp[next][nhour], ncost);
                        que.push(PP(ncost, P(nhour, next)));
                    }
                }
            }

            for (int j = 0; j <= H; j++) {
                ans = min(ans, dp[T][j] + dp_p[i]);
            }
        }

        if (ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}
