#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> PP;

class Union_Find
{
public:
    vector<int> par;

    void init(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x < y) par[y] = x;
        else par[x] = y;
    }
};

int N, M;

void solve() {
    vector<PP> V;
    for (int i = 0; i < M; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        V.push_back(PP(c, P(x, y)));
    }

    sort(V.begin(), V.end());

    vector<bool> used(N, false);
    int count = 0;
    Union_Find uf;
    uf.init(N);
    for (int i = 0; i < M; i++) {
        PP pp = V[i];
        int cost = pp.first;
        int x = pp.second.first;
        int y = pp.second.second;
        if (uf.find(x) == uf.find(y)) continue;
        count++;
        uf.unite(x, y);

        if (count == (N + 1) / 2) {
            cout << cost << endl;
            return ;
        }
    }
}

int main() {
    while (cin >> N >> M, N || M) solve();

    return 0;
}
