#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

const int INF = 1 << 28;

int main ()
{
    int n;
    while (cin >> n, n) {
        vector<vector<int> > edge(n+1, vector<int>(n+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                cin >> edge[j][i];
            }
        }

        vector<int> ver(1 << n, INF);
        queue<P> q;

        for (int i = 0; i < n; i++) {
            ver[1 << i] = edge[0][i+1];
            q.push(P(1 << i, edge[0][i+1]));
        }
        while (q.size()) {
            P p = q.front(); q.pop();
            int v = p.first;
            int cost = p.second;

            if (ver[v] < cost) continue;

            for (int i = 0; i < n; i++) {
                if ((v & (1 << i)) == 0) {
                    int cost_ = cost + edge[0][i+1];
                    int to_ = v | (1 << i);
                    if (ver[to_] > cost_) {
                        ver[to_] = cost_;
                        q.push(P(to_, cost_));
                    }
                }
            }

            
            for (int i = 0; i < n; i++) {
                if ((v & (1 << i)) == 0) {
                    for (int j = 0; j < n; j++) {
                        if (v & (1 << j)) {
                            int cost_ = cost + edge[j+1][i+1];
                            int to_ = v | (1 << i);
                            if (ver[to_] > cost_) {
                                ver[to_] = cost_;
                                q.push(P(to_, cost_));
                            }
                        }
                    }
                }
            }
        }

        cout << ver[(1 << n) - 1] << endl;
    }

    return 0;
}
