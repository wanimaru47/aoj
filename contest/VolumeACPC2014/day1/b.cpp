#include <iostream>
#include <algorithm>
#include <queue>
#define INF 9999
using namespace std;

int h, w;
int d[20][20];
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
char s[] = {'>', 'v', '<', '^'};

int  main ()
{
    cin >> h >> w;
    char map[20][20];
    int sx, sy, gx, gy;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {sx = i; sy = j;}
            else if (map[i][j] == 'G') {gx = i; gy = j;}
        }
    }
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) d[i][j] = INF;

    queue<pair<int,int> > p;
    p.push(pair<int,int>(sx,sy));
    d[sx][sy] = 1;
    while (p.size()) {
        pair<int,int> q;
        int x = (p.front()).first, y = (p.front()).second;
        p.pop();
        if (map[x][y] == '.') {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < h && 0 <= ny && ny < w && (d[nx][ny] == INF || d[nx][ny] > d[x][y] + 1)) {
                    d[nx][ny] = d[x][y] + 1;
                    p.push(pair<int,int>(nx, ny));
                }
            }
        } else if (map[x][y] != 'S') {
            for (int i = 0; i < 4; i++) {
                if (map[x][y] == s[i]) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (0 <= nx && nx < h && 0 <= ny && ny < w && (d[nx][ny] == INF || d[nx][ny] > d[x][y])) {
                        d[nx][ny] = d[x][y];
                        p.push(pair<int,int>(nx, ny));
                    }
                }
            }
        } else {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < h && 0 <= ny && ny < w && (d[nx][ny] == INF || d[nx][ny] > d[x][y] + 1)) {
                    d[nx][ny] = d[x][y];
                    p.push(pair<int,int>(nx, ny));
                }
            }
        }
    }
    if (d[gx][gy] == INF) cout << -1 << endl;
    else cout << d[gx][gy] << endl;

    return 0;
}
