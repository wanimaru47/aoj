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

bool solve(vector<string> &v) {
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
        for (int j = W - 1; j > -1; j--) {
            if (cw[i][j] >= N) {
                changed = true;
                for (int k = j; ; k--) {
                    v[i][k] = '.';
                    if (cw[i][k] == 1) {
                        cw[i][k] = 0;
                        break;
                    }
                    cw[i][k] = 0;
                }
            }
        }
    }

    for (int i = 0; i < W; i++) {
        for (int j = H - 1; j > -1; j--) {
            if (ch[j][i] >= N) {
                changed = true;
                for (int k = j; ; k--) {
                    v[k][i] = '.';
                    if (ch[k][i] == 1) {
                        ch[k][i] = 0;
                        break;
                    }
                    ch[k][i] = 0;
                }
            }
        }
    }

    if (!changed) return false;

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
