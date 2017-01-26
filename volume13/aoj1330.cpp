#include <bits/stdc++.h>
using namespace std;

class uf {
    vector<int> par;
public:
    uf(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (par[x] == x) return x;
        else return (par[x] = find(par[x]));
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x < y) {
            par[y] = x;
        } else {
            par[x] = y;
        }
    }
};

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<char> c(M);
        vector<int> a(M);
        vector<int> b(M);
        vector<int> w(M);
        vector<map<int,int> > dict(N+1);
        set<int> s;
        for (int i = 0; i < M; i++) {
            cin >> c[i] >> a[i] >> b[i];
            if (c[i] == '!') {
                cin >> w[i];
                s.insert(a[i]);
                s.insert(b[i]);
                dict[a[i]][b[i]] = w[i];
                dict[b[i]][a[i]] = -w[i];
            }
        }

        vector<int> dist(N+1, 1111111);
        vector<int> used(N+1);
        for (auto i : s) {
            if (dist[i] != 1111111) continue;

            dist[i] = 0;
            queue<int> que;
            que.push(i);

            while (que.size()) {
                int k = que.front();
                que.pop();
                if (used[k]) continue;

                used[k] = true;
                for (auto p : dict[k]) {
                    if (used[p.first]) continue;
                    dist[p.first] = dist[k] + p.second;
                    que.push(p.first);
                }
            }
        }

        uf t(N+1);
        for (int i = 0; i < M; i++) {
            if (c[i] == '?') {
                if (t.find(a[i]) == t.find(b[i])) {
                    cout << dist[b[i]] - dist[a[i]] << endl;
                } else {
                    cout << "UNKNOWN" << endl;
                }
            } else {
                t.unite(a[i], b[i]);
            }
        }
    }

    return 0;
}
