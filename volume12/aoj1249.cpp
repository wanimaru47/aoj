#include <bits/stdc++.h>
using namespace std;

const int dx[] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const int dy[] = { 1, 0, 1, 1, 0, 0, 0, 1,-1, 1,-1, 1,-1};
const int dz[] = { 0, 1, 1,-1, 0, 1,-1, 0, 0, 1, 1,-1,-1};

int N, M, P;

bool check (vector<vector<vector<int> > > v, int sx, int sy, int sz) {
    for (int i = 0; i < 13; i++) {
        int nx = sx;
        int ny = sy;
        int nz = sz;
        int r = 0;
        int l = 0;
        

        while (0 <= nx && nx < N && 0 <= ny && ny < N && 0 <= nz && nz < P && v[nx][ny][nz] == v[sx][sy][sz]) {
            r++;
            nx += dx[i];
            ny += dy[i];
            nz += dz[i];
        } 

        nx = sx;
        ny = sy;
        nz = sz;
        
        while (0 <= nx && nx < N && 0 <= ny && ny < N && 0 <= nz && nz < P && v[nx][ny][nz] == v[sx][sy][sz]) {
            l++;
            nx -= dx[i];
            ny -= dy[i];
            nz -= dz[i];
        }

        if (l + r - 1 >= M) return true;
    }

    return false;
}

int main ()
{
    while (cin >> N >> M >> P, N || M || P) {
        int flag = -1;
        int win = -1;
        
        vector<vector<vector<int> > > v(N, vector<vector<int> >(N, vector<int>(P, 0)));

        vector<int> p[N][N];

        int carsor = 1;
        for (int i = 0; i < P; i++) {
            int x, y;
            cin >> x >> y;

            p[x-1][y-1].push_back(carsor);
            v[x-1][y-1][p[x-1][y-1].size()-1] = carsor;

            if (check(v, x-1, y-1, (p[x-1][y-1].size()-1)) && flag == -1) flag = i + 1, win = carsor;
            
            carsor = carsor == 1 ? 2 : 1;
        }

        if (win > 0) cout << (win == 1 ? "Black " : "White ") << flag << endl;
        else cout << "Draw" << endl;
    }

    return 0;
}
