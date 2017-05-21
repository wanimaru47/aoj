#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P>  Q;

const int INF = 1<<28;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<vector<int>> v(N), d(N), c(N);
        for (int i = 0; i < M; i++) {
            int x, y, z, w;
            cin >> x >> y >> z >> w;
            x--, y--;
            v[x].push_back(y);
            v[y].push_back(x);
            d[x].push_back(z);
            d[y].push_back(z);
            c[x].push_back(w);
            c[y].push_back(w);
        }

        vector<int> dp(N, INF);
        vector<int> cdp(N, INF);
        int ans = 0;
        priority_queue<P, vector<P>, greater<P>> que;
        dp[0] = 0;
        cdp[0] = 0;
        que.push(P(0,0));
        while (!que.empty()) {
            P p = que.top(); que.pop();
            int now = p.second;
            int dist = p.first;

            if (dp[now] < dist) continue;
            ans += cdp[now];
            
            for (int i = 0; i < v[now].size(); i++) {
                int next = v[now][i];
                int ndist = dist + d[now][i];
                if (dp[next] > ndist) {
                    dp[next] = ndist;
                    cdp[next] = c[now][i];
                    que.push(P(ndist, next));
                } else if (dp[next] == ndist) {
                    cdp[next] = min(cdp[next], c[now][i]);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
