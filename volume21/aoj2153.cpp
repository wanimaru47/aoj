#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
bool d[55][55][55][55];

int main() {
    int n, m;
    while (cin >> n >> m, n || m) {
        vector<string> G1(m), G2(m);
        queue<P> que1, que2;
        for (int i = 0; i < 55; i++)
            for (int j = 0; j < 55; j++)
                for (int l = 0; l < 55; l++)
                    for (int k = 0; k < 55; k++)
                        d[i][j][k][l] = true;
        for (int i = 0; i < m; i++) {
            cin >> G1[i] >> G2[i];
            for (int j = 0; j < n; j++) {
                if (G1[i][j] == 'L') que1.push(P(i, j));
                if (G2[i][j] == 'R') que2.push(P(i, j));
            }
        }

        d[que1.front().first][que1.front().second][que2.front().first][que2.front().second] = false;

        bool res = false;
        while (1) {
            if (!que1.size() || !que2.size()) break;
            P p1 = que1.front(); que1.pop();
            P p2 = que2.front(); que2.pop();

            int x1 = p1.first;
            int y1 = p1.second;
            int x2 = p2.first;
            int y2 = p2.second;
            for (int i = 0; i < 4; i++) {
                int nx1 = x1 + dx[i];
                int ny1 = y1 + dy[i];
                int nx2 = x2 + dx[i];
                int ny2 = y2 - dy[i];

                if ( nx1 < 0 || nx1 >= m || ny1 < 0 || ny1 >= n || G1[nx1][ny1] == '#') nx1 = x1, ny1 = y1;
                if ( nx2 < 0 || nx2 >= m || ny2 < 0 || ny2 >= n || G2[nx2][ny2] == '#') nx2 = x2, ny2 = y2;

                if (G1[nx1][ny1] == '%' && G2[nx2][ny2] == '%') {
                    res = true;
                    break;
                }
                if (G1[nx1][ny1] == '%' || G2[nx2][ny2] == '%') continue;
                if (d[nx1][ny1][nx2][ny2]) {
                    d[nx1][ny1][nx2][ny2] = false;
                    que1.push(P(nx1, ny1));
                    que2.push(P(nx2, ny2));
                }
            }
        }

        cout << (res ? "Yes" : "No") << endl;
    }

    return 0;
}
