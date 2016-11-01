#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
const int INF = 1 << 28;

int main() {
    int N, K;
    while (cin >> N >> K, N || K) {
        vector<vector<P> > V(N+1);
        while (K--) {
            int f;
            cin >> f;
            if (f) {
                int c, d, e;
                cin >> c >> d >> e;
                V[c].push_back(P(e, d));
                V[d].push_back(P(e, c));
            } else {
                int a, b;
                cin >> a >> b;

                priority_queue<P, vector<P>, greater<P> > que;
                vector<int> dp(N+1, INF);
                dp[a] = 0;
                que.push(P(0, a));

                while (que.size()) {
                    P p = que.top(); que.pop();
                    int now = p.second;
                    int cost = p.first;

                    if (dp[now] < cost) continue;

                    for (int i = 0; i < V[now].size(); i++) {
                        int next = V[now][i].second;
                        int ncost = V[now][i].first + cost;

                        if (dp[next] > ncost) {
                            dp[next] = ncost;
                            que.push(P(ncost, next));
                        }
                    }
                }

                if (dp[b] == INF) cout << -1 << endl;
                else cout << dp[b] << endl;
            }
        }
    }

    return 0;
}
