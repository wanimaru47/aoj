#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<P> vp;
typedef vector<vp> mp;

int N, M;

int solve(mp& m, int s, int t) {

    priority_queue<P, vector<P>, greater<P> > que;
    vector<int> dp(M, 1 << 28);
    dp[s] = 0;

    for (int i = 0; i < m[s].size(); i++) {
        que.push(m[s][i]);
        dp[m[s][i].second] = m[s][i].first;
    }

    while (que.size()) {
        P p  = que.top(); que.pop();
        int now = p.second;
        int cost = p.first;

        if (dp[now] < cost) continue;

        for (int i = 0; i < m[now].size(); i++) {
            int cost_ = cost + m[now][i].first;
            int next = m[now][i].second;

            if (dp[next] > cost_) {
                que.push(P(cost_, next));
                dp[next] = cost_;
            }
        }
    }

    return dp[t];
}

int main() {

    while (cin >> N >> M, N || M) {
        mp mc(M), mt(M);

        for (int i = 0; i < N; i++) {
            int a, b, c, t;
            cin >> a >> b >> c >> t;
            a--, b--;
            mc[a].push_back(P(c, b));
            mc[b].push_back(P(c, a));
            mt[a].push_back(P(t, b));
            mt[b].push_back(P(t, a));
        }

        int Q;
        cin >> Q;

        while (Q--) {
            int a, b, t;
            cin >> a >> b >> t;
            a--, b--;

            if (!t) {
                cout << solve(mc, a, b) << endl;
            } else {
                cout << solve(mt, a, b) << endl;
            }
        }
    }

    return 0;
}
