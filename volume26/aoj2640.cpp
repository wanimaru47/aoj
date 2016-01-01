#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> PP;
typedef pair<PP,P> PPP;
typedef priority_queue<PPP, vector<PPP>, greater<PPP>> PQ;

string str = "^>v<";
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const int dx_[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy_[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main () {
    int N, M, sx, sy, sdir;
    cin >> N >> M;
    vector<string> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        for (int j = 0; j < M; j++) {
            auto flag = find(str.begin(), str.end(), v[i][j]) - str.begin();
            if (flag < str.size()) {
                sx = i;
                sy = j;
                sdir = flag;
            }
        }
    }

    PQ que;
    int d[N][M][4][4];
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++)
            for (int k = 0; k < 4; k++) 
                for (int l = 0; l < 4; l++) d[i][j][k][l] = 1 << 28;

    for (int i = 0; i < 4; i++) {
        int nx, ny;
        nx = sx + dx_[(2 * sdir + i) % 8];
        ny = sy + dy_[(2 * sdir + i) % 8];
        if (0 <= nx && nx < v.size() && 0 <= ny && ny < v[nx].size()) {
            if (v[nx][ny] == '#') {
                que.push(PPP(PP(0, P(i, sdir)), P(sx, sy)));
                d[sx][sy][sdir][i] = 0;
            }
        } else {
            que.push(PPP(PP(0, P(i, sdir)), P(sx, sy)));
            d[sx][sy][sdir][i] = 0;
        }
    }
    
    int res = 1 << 28;
    while (que.size()) {
        PPP pp = que.top(); que.pop();
        int x = pp.second.first;
        int y = pp.second.second;
        int dir = pp.first.second.second;
        int c = pp.first.second.first;
        int cost = pp.first.first;

        if (d[x][y][dir][c] < cost) continue;
        if (v[x][y] == 'G') res = min(res, cost);

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (0 <= nx && nx < N && 0 <= ny && ny < M && v[nx][ny] != '#') {
            if ((c == 1 || c == 2) && d[nx][ny][dir][c + 1] > cost + 1) {
                d[nx][ny][dir][c + 1] = cost + 1;
                que.push(PPP(PP(cost + 1, P(c + 1, dir)), P(nx, ny)));
            }
        }
        if ((c == 2 || c == 3) && d[x][y][(dir + 1) % 4][c - 2] > cost + 1) {
            d[x][y][(dir + 1) % 4][c - 2] = cost + 1;
            que.push(PPP(PP(cost + 1, P(c - 2, (dir + 1) % 4)), P(x, y)));
        }
        if ((c == 0 || c == 1) && d[x][y][(dir + 3) % 4][c + 2] > cost + 1) {
            d[x][y][(dir + 3) % 4][c + 2] = cost + 1;
            que.push(PPP(PP(cost + 1, P(c + 2, (dir + 3) % 4)), P(x, y)));
        }

        for (int i = 0; i < 4; i++) {
            if (c == i) continue;
            int nx = x + dx_[(2 * dir + i) % 8];
            int ny = y + dy_[(2 * dir + i) % 8];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (v[nx][ny] == '#' && d[x][y][dir][i] > cost + 1) {
                    d[x][y][dir][i] = cost + 1;
                    que.push(PPP(PP(cost + 1, P(i, dir)), P(x, y)));
                }
            } else {
                if (d[x][y][dir][i] > cost + 1) {
                    d[x][y][dir][i] = cost + 1;
                    que.push(PPP(PP(cost + 1, P(i, dir)), P(x, y)));
                }
            }
        }
    }

    cout << (res < (1 << 28) ? res : -1) << endl;
    
    return 0;
}
