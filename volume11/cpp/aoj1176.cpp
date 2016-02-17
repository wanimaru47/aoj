#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

const int INF = 1000000;

int H, W, S;
int sum;

P dp[33][33][33][33];

P div(mat &v, int x, int y, int h, int w) {
    if (dp[x][y][h][w].first > 0) return dp[x][y][h][w]; 

    auto Area = [&]() -> int {
        int punder = (x > 0 && y > 0) ? v[x - 1][y - 1] : 0;
        int funder = (x > 0) ? v[x - 1][y + w - 1] : 0;
        int ptop = (y > 0) ? v[x + h - 1][y - 1] : 0;
        int ftop = v[x + h - 1][y + w - 1]; 

        return ftop - funder - ptop + punder;
    };

    if (Area() < sum - S) return P(-INF, -INF);

    P res = P(1, S - (sum - Area()));

    auto Max = [&](P p) {
        if (p.first > res.first) {
            res.first = p.first;
            res.second = p.second;
        } else if (p.first == res.first) {
           res.second = max(res.second, p.second);
        }
    };

    for (int i = 1; i < h; i++) {
        P p1 = div(v, x, y, i, w);
        P p2 = div(v, x + i, y, h - i, w);

        if (p1.first <= 0 && p2.first <= 0) continue;

        P tmp = P(p1.first + p2.first, min(p1.second, p2.second));
        Max(tmp);
    }

    for (int j = 1; j < w; j++) {
        P p1 = div(v, x, y, h, j);
        P p2 = div(v, x, y + j, h, w - j);

        if (p1.first <= 0 && p2.first <= 0) continue;

        P tmp = P(p1.first + p2.first, min(p1.second, p2.second));
        Max(tmp);
    }

    dp[x][y][h][w].first = res.first;
    dp[x][y][h][w].second = res.second;


    return res;
}

void solve(mat d) {
    auto v = d;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int up = i > 0 ? v[i - 1][j] : 0;
            int left = j > 0 ? v[i][j - 1] : 0;
            int sub = (i > 0 && j > 0) ? v[i - 1][j - 1] : 0;
            v[i][j] += up + left - sub;
        }
    }

    P res = div(v, 0, 0, H, W);

    cout << res.first << " " << res.second << endl;
}

int main() {
    while (cin >> H >> W >> S, H || W || S) {
        for (int i = 0; i < 33; i++) {
            for (int j = 0; j < 33; j++) {
                for (int k = 0; k < 33; k++) {
                    for (int l = 0; l < 33; l++) {
                        dp[i][j][k][l].first = -1;
                        dp[i][j][k][l].second = -1;
                    }
                }
            }
        }

        mat d(H, vec(W));
        sum = 0;
        for (auto &v : d) {
            for (auto &c : v) {
                cin >> c;
                sum += c;
            }
        }

        solve(d);
    }

    return 0;
}
