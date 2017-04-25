#include <bits/stdc++.h>
using namespace std;

struct UniFi {
    vector<int> par;

    UniFi(int n):par(n) {
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int is_par(int x) {
        if (x == par[x]) return x;
        else return par[x] = is_par(par[x]);
    }

    void unite(int x, int y) {
        x = is_par(x);
        y = is_par(y);

        if (x < y) par[y] = x;
        else par[x] = y;
    }

    int count() {
        int ret = 0;
        for (int i = 0; i < par.size(); i++) {
            if (i == par[i]) ret++;
        }
        return ret;
    }
};

int main() {
    int N, H, W;
    cin >> N >> H >> W;

    UniFi uf(N);
    vector<vector<pair<int,int> > > x(H), y(W);
    vector<vector<int> > v(4);
    for (int i = 0; i < N; i++) {
        int _x, _y;
        cin >> _x >> _y;
        _x--, _y--;
        x[_x].push_back(make_pair(_y, i));
        y[_y].push_back(make_pair(_x, i));
        if (_x == 0) v[0].push_back(i);
        if (_x == H-1) v[1].push_back(i);
        if (_y == 0) v[2].push_back(i);
        if (_y == W-1) v[3].push_back(i);
    }

    for (int i = 0; i < H; i++) {
        int point;
        if (x[i].size()) point = x[i][0].second; 
        else continue;
        for (auto p : x[i]) {
            uf.unite(point, p.second);
        }
    }
    for (int i = 0; i < W; i++) {
        int point;
        if (y[i].size()) point = y[i][0].second; 
        else continue;
        for (auto p : y[i]) {
            uf.unite(point, p.second);
        }
    }
    int count = uf.count();
    int ans = 1 << 28;
    if (count > 1) {
        for (int i = 0; i < 4; i++) {
            set<int> s;
            for (auto j : v[i]) s.insert(uf.is_par(i));
            ans = min(ans, count - (int)s.size());
        }
    } else {
        ans = 0;
    }
    cout << ans + N - 1 << endl;

    return 0;
}
