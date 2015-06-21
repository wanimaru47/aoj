#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int INF = 1 << 28;

int main ()
{
    int n, m;
    while (cin >> m >> n, n || m) {
        vector<vector<vector<int> > > grid(n, vector<vector<int> >(m, vector<int>(11, 0)));
        vector<vector<vector<bool> > > d(n, vector<vector<bool> >(m, vector<bool>(11, false)));


        int sx, sy;
        int ex, ey;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int corsor; cin >> corsor;
                for (int i = 0; i <= 10; i++) {
                    grid[i]
                }
                if (grid[i][j] == 2) sx = i, sy = j; 
                if (grid[i][j] == 3) ex = i, ey = j; 
            }
        }

        queue<pair<int, P> > q;
        q.push(pair<int,P>(1, P(sx,sy)));
        d[sx][sy][1] = true;

        int res = -1;
        
        while (q.size()) {
            pair<int,P> p = q.front(); q.pop();
            int times = p.first;
            int x = p.second.first;
            int y = p.second.second;

            if (d[x][y][10]) continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int count = 0;

                while (0 <= nx && nx < n && 0 <= ny && ny < m && (grid[nx][ny] == 0 || grid[nx][ny] == 3)) {
                    if (grid[nx][ny] == 3) {
                        res = times;
                        break;
                    }
                    nx += dx[i];
                    ny += dy[i];
                    count++;
                }
                if (res > 0) break;
                if (0 <= nx && nx < n && 0 <= ny && ny < m && count && !d[nx - dx[i]][ny - dy[i]][times+1]) {
                    grid[nx][ny] = 0;
                    nx -= dx[i];
                    ny -= dy[i];
                    d[nx][ny][times+1] = true;
                    q.push(pair<int,P>(times + 1, P(nx,ny)));
                }
            }
            if (res > 0) break;
        }

        cout << res << endl;
    }

    return 0;
}
