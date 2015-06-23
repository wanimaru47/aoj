#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> PP;
typedef pair<int,PP> PPP;

const int INF = 1 << 28;

int main () {
    int n, m, l;
    while (cin >> n >> m >> l, n + m + l) {
        vector<vector<PP> > Path(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b, d, e;
            cin >> a >> b >> d >> e;
            Path[a].push_back(PP(b, P(d, e)));
            Path[b].push_back(PP(a, P(d, e)));
        }

        priority_queue<PP, vector<PP>, greater<PP> > pq;
        vector<vector<int> > dp(n + 1, vector<int>(l + 1, INF));

        dp[1][l] = 0;
        pq.push(PP(0, P(l, 1)) );

        int res = INF;
        
        while (pq.size()) {
            PP pp = pq.top(); pq.pop();
            int attack = pp.first;
            int money = pp.second.first;
            int now = pp.second.second;

            if (dp[now][money] < attack) continue;

            for (int i = 0; i < Path[now].size(); i++) {
                int next = Path[now][i].first;
                int M = Path[now][i].second.first;
                int A = Path[now][i].second.second;
                if (money >= M && dp[next][money - M] > attack) {
                    dp[next][money - M] = attack;
                    pq.push(PP(attack, P(money - M, next)));
                    if (next == n) {
                        res = min(res, attack);
                    }
                }

                if (money >= 0 && dp[next][money] > attack + A) {
                    dp[next][money] = attack + A;
                    pq.push(PP(attack + A, P(money, next)));
                    if (next == n) {
                        res = min(res, attack + A);
                    }
                }
            }
        }

        cout << res << endl;
        
    }

    return 0;
}
