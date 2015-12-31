#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<P,P> PP;
typedef priority_queue<PP, vector<PP>, greater<PP>> PQ;

string str = "^>v<";
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const int dx_[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy_[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool check(vector<string> &v, int x, int y, int dir) {
    for (int i = 0; i < 4; i++) {
        int nx, ny;
        nx = x + dx_[(2 * dir + i) % 8];
        ny = y + dy_[(2 * dir + i) % 8];
        if (0 <= nx && nx < v.size() && 0 <= ny && ny < v[nx].size()) {
            if (v[nx][ny] == '#') return true;
        } else return true;
    }

    return false;
}

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

    int d[N][M][4];
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++)
            for (int k = 0; k < 4; k++) d[i][j][k] = 1 << 28;
    d[sx][sy][sdir] = 0;

    PQ que;
    que.push(PP(P(0, sdir), P(sx, sy)));
    
    int res = 1 << 28;
    while (que.size()) {
        PP pp = que.top(); que.pop();
        int x = pp.second.first;
        int y = pp.second.second;
        int dir = pp.first.second;
        int cost = pp.first.first;

        if (d[x][y][dir] < cost) continue;
        if (v[x][y] == 'G') res = min(res, cost);

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (0 <= nx && nx < N && 0 <= ny && ny < M && v[nx][ny] != '#' && d[nx][ny][dir] > cost + 1) {
            if (check(v, nx, ny, dir)) {
                d[nx][ny][dir] = cost + 1;
                que.push(PP(P(cost + 1, dir), P(nx, ny)));
            }
        }
        if (d[x][y][(dir + 1) % 4] > cost + 1) {
            if (check(v, x, y, (dir + 1) % 4)) {
                d[x][y][(dir + 1) % 4] = cost + 1;
                que.push(PP(P(cost + 1, (dir + 1) % 4), P(x, y)));
            }
        }
        if (d[x][y][(dir + 3) % 4] > cost + 1) {
            if (check(v, x, y, (dir + 3) % 4)) {
                d[x][y][(dir + 3) % 4] = cost + 1;
                que.push(PP(P(cost + 1, (dir + 3) % 4), P(x, y)));
            }
        }
    }

    cout << (res < (1 << 28) ? res : -1) << endl;
    
    return 0;
}
