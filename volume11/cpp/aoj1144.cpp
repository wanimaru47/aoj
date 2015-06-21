#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 28;
int res;

int dx[] = {0, 1, 0,-1};
int dy[] = {1, 0,-1, 0};

int solve (int count, vector<vector<int> > v, int x, int y) {
    if (count > res || count >= 10) return INF;
    if (v[x][y] == 3) return count;

    int ret = INF;
    for (int i = 0; i < 4; i++) {
        vector<vector<int> > tmp(v.begin(), v.end());
        int nx = x + dx[i];
        int ny = y + dy[i];
        bool flag = false;
        while (0 <= nx && nx < tmp.size() && 0 <= ny && ny < tmp[0].size() && (tmp[nx][ny] == 0 || tmp[nx][ny] == 3)) {
            flag = true;
            if (tmp[nx][ny] == 3) {
                return count+1;
            }
            nx += dx[i];
            ny += dy[i];
        }
        if (0 <= nx && nx < tmp.size() && 0 <= ny && ny < tmp[0].size() && flag) {
            tmp[nx][ny] = 0;
            ret = min(solve(count + 1, tmp, nx - dx[i], ny - dy[i]), ret);
        }
    }

    return ret;
}

int main () {
    int n, m;
    while (cin >> m >> n, n || m) {
        res = INF;
        vector<vector<int> > v(n, vector<int>(m));
        int sx, sy;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int num; cin >> num;
                if (num == 2) sx = i, sy = j, num = 0;
                v[i][j] = num;
            }
        }
        int res = solve (0, v, sx, sy);

        cout << (res == INF ? -1 : res) << endl;
    }

    return 0;
}
