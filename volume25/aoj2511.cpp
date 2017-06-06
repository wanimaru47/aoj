#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int n, m;

bool is_connected(vector<vector<int>>& v, vector<int>& used, int start) {
    int n = v.size();
    queue<int> que;
    que.push(start);

    while (que.size()) {
        int now = que.front();
        que.pop();

        if (used[now]) continue;
        used[now] = true;

        for (int j = 0; j < n; j++) {
            if (v[now][j] >= 0 && !used[j]) {
                que.push(j);
            } 
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) return false;
    }

    return true;
}

int bfs(priority_queue<P, vector<P>, greater<P>>& que, vector<int>& used, vector<vector<int>>& v) {
    int sum = 0;
    while (que.size()) {
        P p = que.top(); que.pop();
        int now = p.second;
        int cost = p.first;

        if (used[now]) continue;
        used[now] = true;
        sum += cost;

        for (int i = 0; i < n; i++) {
            if (v[now][i] >= 0 && !used[i]) {
                que.push(P(v[now][i], i));
            }
        }
    }

    return sum;
}

int main() {
    while (cin >> n >> m, n || m) {
        map<int,vector<int>> h;
        for (int i = 0; i < n; i++) {
            int _h;
            cin >> _h;

            h[_h].push_back(i);
        }

        vector<vector<int>> v(n, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            int x, y, c;
            cin >> x >> y >> c;
            --x, --y;
            v[x][y] = v[y][x] = c;
        }

        {
            vector<int> tmp(n, false);
            if (!is_connected(v, tmp, 0)) {
                cout << 0 << endl;
                continue;
            }
        }

        bool erased[200], merged[200];
        memset(erased, 0, sizeof(erased));
        memset(merged, 0, sizeof(erased));
        int ans = 0;

        for (auto l: h) {
            auto vec = l.second;
            bool _erased[200];
            for (int i = 0; i < n; i++) _erased[i] = erased[i];
            for (auto i: vec) erased[i] = true;

            vector<int> used(n, false);
            int unremoved_idx = -1;
            for (int i = 0; i < n; i++) {
                if (erased[i]) used[i] = true;
                else unremoved_idx = i;
            }

            bool flag = true;
            if (unremoved_idx >= 0 && !is_connected(v, used, unremoved_idx)) {
                flag = false;
            }

            if (flag) {
                for (auto i: vec) used[i] = false;
                priority_queue<P, vector<P>, greater<P>> q;
                for (int i = 0; i < vec.size(); i++) {
                    for (int j = 0; j < n; j++) {
                        if (v[vec[i]][j] >= 0 && !_erased[j] && used[j]) {
                            q.push(P(v[vec[i]][j], vec[i]));
                        }
                    }
                }

                if (q.size() == 0) {
                    for (int j = 0; j < n; j++) {
                        if (v[vec[0]][j] >= 0 && !used[j]) q.push(P(v[vec[0]][j], j)), used[vec[0]] = true;
                    }
                }

                ans += bfs(q, used, v);
            } else {
                for (int i = 0; i < n; i++) {
                    used[i] = _erased[i];
                }

                priority_queue<P, vector<P>, greater<P>> q;
                for (int i = 0; i < n; i++) {
                    if (v[vec[0]][i] >= 0 && !used[i]) {
                        q.push(P(v[vec[0]][i], i));
                        used[vec[0]] = true;
                    }
                }

                ans += bfs(q, used, v);
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
