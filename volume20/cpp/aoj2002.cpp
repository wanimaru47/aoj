#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int N, M;

P check(vector<vector<char> > &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] != '.') return P(i, j);
        }
    }

    return P(-1, -1);
}

int main ()
{
    int X; cin >> X;
    while (cin >> N >> M, X--) {
        vector<vector<char> > v(N, vector<char>(M));
        for (auto &i : v) for (auto &j : i) cin >> j;

        P start;
        bool res = true;
        while ((start = check(v)) != P(-1,-1)) {
            char S = v[start.first][start.second];
            vector<P> chain;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (v[i][j] == S)chain.push_back(P(i,j));
                }
            }
            sort(chain.begin(), chain.end());
            int sx = chain[0].first;
            int sy = chain[0].second;
            int gx = chain[chain.size()-1].first;
            int gy = chain[chain.size()-1].second;
            int num = (gx - sx + 1) * (gy - sy + 1);

            cout << "OK" << endl;
            if (num == chain.size()) {
                for (int i = sx; i <= gx; i++) {
                    for (int j = sy; j <= gy; j++) {
                        if (S != v[i][j]) res = false;
                    }
                }
            } else {
                // if (!(sx == chain[1].first && sy + 1 == chain[1].second) && !(sy == chain[1].second && sx == chain[1].first + 1)) res = false;
                if (!(chain[1].first <= sx && sx <= gx && sy + 1 == chain[1].second) && !(chain[1].second <= sy && sy <= gy && sx + 1 == chain[1].first)) res = false;
                sx = chain[1].first;
                sy = chain[1].second;
                num = (gx - sx + 1) * (gy - sy + 1);
                if (num == chain.size() - 1) {
                    for (int i = sx; i <= gx; i++) {
                        for (int j = sy; j <= gy; j++) {
                            if (S != v[i][j]) res = false;
                        }
                    }
                } else {
                    sx = chain[0].first;
                    sy = chain[0].second;
                    gx = chain[chain.size()-2].first;
                    gy = chain[chain.size()-2].second;
                    if (!(sy <= chain[chain.size() - 1].second && chain[chain.size() - 1].second <= gy && gx + 1 == chain[chain.size() - 1].first)
                        && !(sx <= chain[chain.size()-1].first && chain[chain.size() - 1].first <= gx && gy + 1 == chain[chain.size() - 1].second)) res = false;
                    num = (gx - sx + 1) * (gy - sy + 1);
                    if (num == chain.size() - 1) {
                        for (int i = sx; i <= gx; i++) {
                            for (int j = sy; j <= gy; j++) {
                                if (S != v[i][j]) res = false;
                            }
                        }
                    }
                }
            }
            if (res == false) break;
            else {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        if (S == v[i][j]) v[i][j] = '.';
                    }
                }
            }
        }
        cout << (res ? "YES" : "NO") << endl;
    }

    return 0;
}
