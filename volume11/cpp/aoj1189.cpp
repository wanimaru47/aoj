#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
int main ()
{
    const int INF = 1 << 28;
    const int MAX = 1000000;
    const int dx[] = { 1, 0,-1, 0};
    const int dy[] = { 0,-1, 0, 1};
    const int dm[] = {-1, 0, 1};
    int n, m;
    map<P, int> M;
    vector<P> d(MAX+1, P(INF,INF));

    M[P(0,0)] = 1;
    d[1] = P(0,0);
    int x = 1, y = 0;
    int c = 1;
    for (int i = 2; i <= MAX; i++) {
        c %= 4;
        int cdir = 4 + c - 1;
        cdir %= 4;
        int sy = y - dy[cdir], sx = x - dx[cdir];
        M[P(y,x)] = i;
        d[i] = P(y,x);
         if (M.find(P(sy,sx)) != M.end()) {
            x += dx[c];
            y += dy[c];
         } else {
             x = sx;
             y = sy;
             c++;
         }
    }
    
    vector<bool> prim(MAX+1, true);
    prim[0] = prim[1] = false;
    for (int i = 2; i <= MAX / 2; i++) {
        for (int j = 2; prim[i] && j * i <= MAX; j++) {
            prim[i * j] = false;
        }
    }

    while (cin >> n >> m , n + m) {
        int res = 0;
        int res_n = 0;
        queue<pair<int,P> > q;

        vector<int> count(MAX+1, 0);
        if (prim[m]) {
            count[m] = 1;
            q.push(pair<int,P>(1, d[m]));
            res = 1;
            res_n = m;
        } else {
            count[m] = 0;
            q.push(pair<int,P>(0, d[m]));
        }

        vector<bool> used(MAX + 1, false);

        while (q.size()) {
            pair<int,P> pp = q.front(); q.pop();
            P p = pp.second;
            int num = M[p];
            int ret = pp.first;

            if (count[num] > ret) continue;
            used[num] = true;
            y = p.first, x = p.second;
            for (int i = 0; i < 3; i++) {
                int ny = y + 1, nx = x + dm[i];
                if (M.find(P(ny, nx)) != M.end() && M[P(ny,nx)] <= n) {
                    int t_n = M[P(ny,nx)];
                    if (count[t_n] == 0 || count[t_n] < count[num] + (prim[t_n] ? 1 : 0)) {

                        if (!used[t_n] || count[t_n] < count[num] + (prim[t_n] ? 1 : 0)) {
                            count[t_n] = count[num] + (prim[t_n] ? 1 : 0);
                            q.push(pair<int,P>(count[t_n], P(ny,nx)));
                            used[t_n] = true;
                        }
                        if (res <= count[t_n] && prim[t_n]) {
                            if (res < count[t_n]) {
                                res = count[t_n];
                                res_n =  t_n;
                            } else {
                                res_n = max(t_n, res_n);
                            }
                        }
                    }
                }
            }
        }

        if (res == 0)
            cout << 0 << " " << 0 << endl;
        else 
            cout << res << " " << res_n << endl;
    }

    return 0;
}
