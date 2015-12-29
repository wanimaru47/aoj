#include <bits/stdc++.h> 
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> PP;
typedef priority_queue<PP, vector<PP>, greater<PP>> QUE;

int d[101][101][101][101];

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    map<char,int> dx, dy;
    dx['U'] = -1, dy['U'] = 0;
    dx['D'] = 1, dy['D'] = 0;
    dx['L'] = 0, dy['L'] = -1;
    dx['R'] = 0, dy['R'] = 1;

    for(int i = 0; i < N; i++) {
        int sx, sy;
        cin >> sy >> sx;
        int times; cin >> times;
        string code; cin >> code;
        for (int time = 0; time < times; time++) {
            for (int j = 0; j < code.size(); j++) {
                int nx = sx + dx[code[j]];
                int ny = sy + dy[code[j]];
                if (!(0 <= nx && nx < H && 0 <= ny && ny < W)) continue;
                if (code[j] == 'R') {
                    d[nx][ny][nx + 1][ny] += 1;
                    d[nx + 1][ny][nx][ny] += 1;
                } else if (code[j] == 'L') {
                    d[sx][sy][sx + 1][sy] += 1;
                    d[sx + 1][sy][sx][sy] += 1;
                } else if (code[j] == 'U') {
                    d[sx][sy][sx][sy + 1] += 1;
                    d[sx][sy + 1][sx][sy] += 1;
                } else {
                    d[nx][ny][nx][ny + 1] += 1;
                    d[nx][ny + 1][nx][ny] += 1;
                }
                sx = nx;
                sy = ny;
            }
        }
    }

    QUE que;
    que.push(PP(0, P(x1,y1)));
    int D[101][101];
    int res = 1 << 28;

    for (int i = 0; i <= H; i++)
        for (int j = 0; j <= W; j++)
            D[i][j] = 1 << 28;

    while(que.size()) {
        PP pp = que.top(); que.pop();
        int cost = pp.first;
        int x = pp.second.first;
        int y = pp.second.second;

        if (x == x2 && y == y2) res = min(res, cost);
        if (D[x][y] < cost) continue;

        int ddx[] = {0, 1, 0, -1};
        int ddy[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int nx = x + ddx[i];
            int ny = y + ddy[i];
            int cost_ = cost + d[x][y][nx][ny];

            if (0 <= nx && nx <= H && 0 <= ny && ny <= W && D[nx][ny] > cost_) {
                D[nx][ny] = cost_;
                que.push(PP(cost_, P(nx,ny)));
            }
        }
    }

    cout << res << endl;

    return 0;
}
