#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int H, W, N;

bool check(vector<string> &v) {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (v[i][j] != '.') return false;
    return true;
}

void fall(vector<string> &v) {
    for (int i = 0; i < W; i++) {
        for (int j = H - 1; j > -1; j--) {
            if (v[j][i] == '.') {
                int k = 1;
                while (j - k > -1 && v[j - k][i] == '.') k++;
                if (j - k > -1) {
                    v[j][i] = v[j - k][i];
                    v[j - k][i] = '.';
                }
            }
        }
    }
}

bool solve(vector<string> &v) {
    fall(v);
    if (check(v)) return true;

    mat cw(H, vec(W, 0));
    auto ch = cw;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W - 1; j++) {
            if (v[i][j] != '.') cw[i][j]++;
            if (v[i][j] == v[i][j+1]) cw[i][j+1] += cw[i][j];
        }
        if (v[i][W-1] != '.') cw[i][W-1]++;
    }

    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H - 1; i++) {
            if (v[i][j] != '.') ch[i][j]++;
            if (v[i][j] == v[i+1][j]) ch[i+1][j] += ch[i][j];
        }
        if (v[H-1][j] != '.') ch[H-1][j]++;
    }

    bool changed = false;
    for (int i = 0; i < H; i++) {
        for (int j = W - 1; j >= N - 1; j--) {
            if (cw[i][j] >= N) {
                changed = true;
                for (int k = cw[i][j] - 1; k > -1; k--) {
                    v[i][j - k] = '.';
                    cw[i][j - k] = 0;
                }
            }
        }
    }

    for (int i = 0; i < W; i++) {
        for (int j = H - 1; j > -1; j--) {
            if (ch[j][i] >= N) {
                changed = true;
                for (int k = ch[j][i] - 1; k > -1; k--) {
                    v[j - k][i] = '.';
                    ch[j - k][i] = 0;
                }
            }
        }
    }

    fall(v);

    if (!changed) return false;
    return solve(v);
}

int main() {
    cin >> H >> W >> N;
    vector<string> v(H);
    for (auto &i : v) {
        cin >> i;
    }


    bool res = false;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W - 1; j++) {
            auto v_ = v;
            v_[i][j] = v[i][j+1];
            v_[i][j+1] = v[i][j];
            res |= solve(v_);
        }
    }

    if (res) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
