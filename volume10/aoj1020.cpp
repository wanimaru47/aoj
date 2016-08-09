#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int main() {
    int N;
    while (cin >> N, N) {
        char s, t, b;
        cin >> s >> t >> b;

        int sx, sy;
        sx = (s - 'A') / 3;
        sy = (s - 'A') % 3;
        int tx, ty;
        tx = (t - 'A') / 3;
        ty = (t - 'A') % 3;
        int bx, by;
        bx = (b - 'A') / 3;
        by = (b - 'A') % 3;
        vector<vector<vector<int> > > dp(N+1, vector<vector<int> >(3, vector<int>(3, 0)));
        dp[0][sx][sy] = 1;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        for (int i = 0; i < N; i++) {
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    for (int j = 0; j < 4; j++) {
                        int nx = x + dx[j];
                        int ny = y + dy[j];
                        if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
                            if (nx == bx && ny == by)
                                dp[i+1][x][y] += dp[i][x][y];
                            else
                                dp[i+1][nx][ny] += dp[i][x][y];
                        } else {
                            dp[i+1][x][y] += dp[i][x][y];
                        }
                    }
                }
            }
        }

        double ans = 0.;
        double p = 1.;
        for (int i = 1; i <= N; i++) {
            p /= 4.;
        }
        ans = p * dp[N][tx][ty];
        printf("%0.9f\n", ans);
    }

    return 0;
}
