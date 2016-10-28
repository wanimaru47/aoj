#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    while (cin >> W >> H, H || W) {
        int sx, sy, gx, gy;
        cin >> sx >> sy >> gx >> gy;
        int M;
        cin >> M;
        vector<vector<int> > d(W+1, vector<int>(H+1));
        vector<vector<int> > used(W+1, vector<int>(H+1));

        for (int i = 0; i < M; i++) {
            int c, dir, x, y;
            cin >> c >> dir >> x >> y;
            if (!dir) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 2; k++) {
                        d[x + j][y + k] = c;
                    }
                }
            } else {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 4; k++) {
                        d[x + j][y + k] = c;
                    }
                }
            }
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        queue<int> qx, qy;
        qx.push(sx);
        qy.push(sy);

        while (qx.size()) {
            int x = qx.front(); qx.pop();
            int y = qy.front(); qy.pop();

            if (used[x][y]) continue;
            used[x][y] = 1;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 < nx && nx <= W && 0 < ny && ny <= H && !used[nx][ny] && d[x][y] == d[nx][ny]) {
                    qx.push(nx);
                    qy.push(ny);
                }
            }
        }

        if (d[gx][gy] > 0 && used[gx][gy]) cout << "OK" << endl;
        else cout << "NG" << endl;
    }

    return 0;
}
