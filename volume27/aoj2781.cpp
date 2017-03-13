#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

const int inf = 1 << 28;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m;
vector<vector<int> > d;
vector<string> vs;

void bfs(int x, int y) {
    queue<P> que;
    que.push(P(x,y));

    while (que.size()) {
        P p = que.front(); que.pop();
        x = p.first;
        y = p.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < m && vs[nx][ny] != '#' && d[nx][ny] > d[x][y] + 1) {
                d[nx][ny] = d[x][y] + 1;
                que.push(P(nx,ny));
            }
        }
    }
}

int main() {
    int sx, sy, gx, gy;
    vector<int> sr, sc;
    cin >> n >> m;
    vs.resize(n);
    for (auto& i : vs) cin >> i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vs[i][j] == '@') sx = i, sy = j;
            if (vs[i][j] == '$') sr.push_back(i), sc.push_back(j);
            if (vs[i][j] == '%') gx = i, gy = j;
        }
    }
    d.resize(n);
    for (auto& i : d) i.resize(m, inf);

    for (int i = 0; i < sr.size(); i++) {
        d[sr[i]][sc[i]] = 0;
        bfs(sr[i], sc[i]);
    }

    queue<P> que;
    que.push(P(sx,sy));
    vector<vector<int> > dist(n, vector<int>(m,inf));
    dist[sx][sy] = 0;

    while (que.size()) {
        P p = que.front(); que.pop();
        int x = p.first;
        int y = p.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < m && vs[nx][ny] != '#' 
                && dist[nx][ny] > dist[x][y] + 1 && dist[x][y] + 1 < d[nx][ny]) {
                dist[nx][ny] = dist[x][y] + 1;
                que.push(P(nx,ny));
            }
        }
    }

    cout << (dist[gx][gy] != inf ? "Yes" : "No") << endl;
    
    return 0;
}
