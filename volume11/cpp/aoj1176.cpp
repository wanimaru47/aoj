#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

int H, W, S;

P div(mat &v, int x, int y, int h, int w) {
    auto Area = [&]() -> int {
        int punder = (x > 0 && y > 0) ? v[x - 1][y - 1] : 0;
        int funder = (x > 0) ? v[x - 1][y + w - 1] : 0;
        int ptop = (y > 0) ? v[x + h - 1][y - 1];
        int ftop = v[x + h - 1][y + w - 1]; 

        return ftop - funder - ptop + punder;
    };
}

void solve(mat d, int& sum) {
    auto v = d;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int up = i > 0 ? v[i - 1][j] : 0;
            int left = j > 0 ? v[i][j - 1] : 0;
            int sub = (i > 0 && j > 0) ? v[i - 1][j - 1];
            v[i][j] += up + left - sub;
        }
    }

    int groups = 0; 
    int surplus = 0;
    P res = div(v, 0, 0, H, W);

    cout << res.first << " " << S - (sum - res.second) << endl;
}

int main() {
    while (cin >> H >> W >> S, H || W || S) {
        mat d(H, vec(W));
        int sum = 0;
        for (auto &v : d) {
            for (auto &c : v) {
                cin >> c;
                sum += c;
            }
        }

        solve(vec, sum);
    }

    return 0;
}
