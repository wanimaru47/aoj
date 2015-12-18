#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> mat;

int n, m;

bool isChange(int &from, int &to, mat &g) {
    auto s = g[from];
    auto t = g[to];
    if (s.size() == 0) return false;
    if (t.size() > 0 && t[t.size() - 1] > s[s.size() - 1]) return false;
    t.push_back(s[s.size() - 1]);
    s.erase(s.begin() + s.size() - 1);
    g[from] = s;
    g[to] = t;

    return true;
}


bool change(int &now, int &pre, mat &g) {
    vector<int> from = {0, 1, 1, 2};
    vector<int> to = {1, 2, 0, 1};
    for (int i = 0; i < 4; i++) {
        if (to[i] == pre && from[i] == now) continue;
        if (isChange(from[i], to[i], g)) {
            now = to[i];
            pre = from[i];

            return true;
        }
    }
    
    return false;
}

int main() {
    while (cin >> n >> m, n || m) {
        mat v(3);
        for (auto &i : v) {
            int c; cin >> c;
            for (int j = 0; j < c; j++) {
                int x; cin >> x;
                i.push_back(x);
            }
        }


        mat g1(3), g2(3);
        for (int i = 1; i <= n; i++) {
            g1[0].push_back(i);
            g2[2].push_back(i);
        }

        int res = 1 << 28;
        vector<int> now = {0, 1, 1, 2};
        vector<int> pre = {1, 0, 2, 1};
        for (int i = 0; i < 4; i++) {
            int tmp = 0;
            auto g(v);
            while (tmp <= m) {
                if (g[0].size() == n || g[2].size() == n) break;
                if (!change(now[i], pre[i], g)) {
                    tmp = 1 << 28;
                    break;
                }
                tmp++;
            }
            res = min(res, tmp);
        }

        cout << (res > m ? -1 : res) << endl;
    }
}
