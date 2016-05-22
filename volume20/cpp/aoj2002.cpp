#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
int N, M;

bool check(vector<vector<char> > &v) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] != '.' && v[i][j] != 'x') return true;
        }
    }

    return false;
}

bool check2(vector<vector<char> > &v, int sx, int sy, int gx, int gy, char str) {
    set<char> res;
    for (int i = sx; i <= gx; i++) {
        for (int j = sy; j <= gy; j++) {
            if (v[i][j] == 'x' || v[i][j] == str);
            else return false;
        }
    }

    return true;
}

vector<int> found(vector<vector<char> > &v, char str) {
    int sx = 1 << 28, sy = 1 << 28, gx = -1, gy = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == str) {
                sx = min(sx, i);
                gx = max(gx, i);
                sy = min(sy, j);
                gy = max(gy, j);
            }
        }
    }
    
    if (check2(v, sx, sy, gx, gy, str)) {
        return vector<int>{sx, sy, gx, gy};
    }

    return vector<int>{-1, -1, -1, -1};
}

void solve() {
    cin >> N >> M;
    vector<vector<char> > v(N, vector<char>(M));
    set<int> s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
            if (v[i][j] != '.') s.insert(v[i][j]);
        }
    }

    bool res = true;

    while (check(v)) {
        bool flag = false;
        auto tmp = s;
        for (auto str : tmp) {
            auto L = found(v, str);

            if (L[0] < 0) {
                continue;
            }
            s.erase(str);
            flag = true;
            for (int i = L[0]; i <= L[2]; i++)
                for (int j = L[1]; j <= L[3]; j++)
                    v[i][j] = 'x';
        }
        if (!flag) {
            res = false;
            break;
        }
    }

    cout << (res ? "SAFE" : "SUSPICIOUS") << endl;
}

int main() {
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        solve();
    }

    return 0;
}
