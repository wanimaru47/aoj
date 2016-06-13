#include <bits/stdc++.h>
using namespace std;

int H, W;
const string DIR = "^>v<";
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    cin >> H >> W;
    vector<vector<char> > V(H + 2, vector<char>(W + 2, '#'));
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> V[i][j];
        }
    }

    int sx, sy, gx, gy, dir;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (V[i][j] == 'G') gx = i, gy = j;
            else if (DIR.find(V[i][j]) != string::npos)
                sx = i, sy = j, dir = DIR.find(V[i][j]);
        }
    }

    vector<vector<vector<bool> > > used(H+2, vector<vector<bool> >(W+2, vector<bool>(4, false)));
    while (!used[sx][sy][dir] && V[sx][sy] != 'G') {
        used[sx][sy][dir] = true;
        int nx = sx + dx[dir * 2];
        int ny = sy + dy[dir * 2];
        int nhx = nx + dx[(dir * 2 + 2) % 8];
        int nhy = ny + dy[(dir * 2 + 2) % 8];
        if (V[nx][ny] == '#') {
            dir = (dir + 3) % 4;
        } else {
            sx = nx;
            sy = ny;

            if (V[nhx][nhy] != '#') {
                dir = (dir + 1) % 4;
            }
        }
    }

    if (V[sx][sy] == 'G') {
        int ans = 1;
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                bool flag = false;
                for (int k = 0; k < 4; k++) {
                    if (used[i][j][k]) flag = true;
                }
                if (flag) ans++;
            }
        }
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
