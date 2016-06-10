#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

const int INF = 1 << 28;
int N, M;

void solve() {
    vector<vector<P> > v(N);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        v[x].push_back(P(z, y));
        v[y].push_back(P(z, x));
    }

    for (auto& i : v) {
        sort(i.begin(), i.end());
    }

    int res = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            priority_queue<P, vector<P>, greater<P> > que;
            vec used(N, false);
            used[i] = used[v[i][j].second] = true;
            for (auto k : v[i]) {
                if (k.first >= v[i][j].first) que.push(k);
            }

            for (auto k : v[v[i][j].second]) {
                if (k.first >= v[i][j].first) que.push(k);
            }

            int Max = v[i][j].first;

            while (que.size()) {
                P p = que.top(); que.pop();
                int w = p.first;
                int now = p.second;
                if (used[now]) continue;
                used[now] = true;
                Max = max(Max, w);
                if (Max - v[i][j].first > res) break;
                for (auto e : v[now]) {
                    int tmp = e.first - v[i][j].first;
                    if (tmp >= 0 && tmp < res && !used[e.second]) {
                        que.push(e);
                    }
                }
            }

            bool flag = true;
            for (int i = 0; i < N; i++) {
                if (!used[i]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                res = min(res, Max - v[i][j].first);
            }
        }
    }

    cout << (res > 10000 ? -1 : res) << endl;
}

int main() {
    while (cin >> N >> M, N || M) solve();

    return 0;
}
