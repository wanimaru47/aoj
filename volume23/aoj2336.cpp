#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int W, H;
int sx, sy, gx, gy;
vector<string> vs;
vector<vector<long double> > gdist;
vector<vector<long double> > sdist;

void make() {
    gdist[gx][gy] = 0;
    queue<P> que;
    que.push(P(gx,gy));
    while (que.size()) {
        P p = que.front(); que.pop();
        int x = p.first, y = p.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < H && 0 <= ny && ny < W && (vs[nx][ny] == '.' || vs[nx][ny] == 's') && gdist[nx][ny] > gdist[x][y] + 1) {
                gdist[nx][ny] = gdist[x][y] + 1;
                que.push(P(nx,ny));
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (vs[i][j] == '*') {
                que.push(P(i,j));
                sdist[i][j] = 0;
            }
        }
    }

    while (que.size()) {
        P p = que.front(); que.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < H && 0 <= ny && ny < W && (vs[nx][ny] == '.' || vs[nx][ny] == 's') && sdist[nx][ny] > sdist[x][y] + 1) {
                sdist[nx][ny] = sdist[x][y] + 1;
                que.push(P(nx,ny));
            }
        }
    }
}

long double check(long double e) {
    long double ret = 0.0;
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (vs[i][j] == '.' || vs[i][j] == 's') {
               long double dist = 1e+50;
               dist = min(dist, gdist[i][j]);
               dist = min(dist, sdist[i][j] + e);
               ret += dist;
               cnt ++;
            }
        }
    }

    return ret / (long double)cnt;
}

int main() {
    cin >> W >> H;
    vs.resize(H);
    gdist.resize(H);
    sdist.resize(H);
    for (auto &i : gdist) i.resize(W, 1e50);
    for (auto &i : sdist) i.resize(W, 1e50);
    for (auto &i : vs) cin >> i;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (vs[i][j] == 'g') gx = i, gy = j;
            if (vs[i][j] == 's') sx = i, sy = j;
        }
    }

    make();

    long double l = 0.0, r = 1e+18;
    for (int c = 0; c < 100; c++) {
        long double m = (l + r)/2.0;
        // printf("%.10Lf\n", m);
        if (check(m) > m) {
            l = m;
        } else {
            r = m;
        }
    }
    printf("%.10Lf\n", min(l + sdist[sx][sy], gdist[sx][sy]));

    return 0;
}
