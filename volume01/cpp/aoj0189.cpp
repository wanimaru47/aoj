#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<P> vec;
typedef vector<vec> mat;

int main() {
    int N;
    while (cin >> N, N) {
        mat m(10);
        vector<vector<int> > dp(10, vector<int>(10, 1 << 28));
        for (int i = 0; i < N; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            dp[a][b] = dp[b][a] = c;

            dp[a][a] = 0;
            dp[b][b] = 0;
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
                }
            }
        }

        int ans = 999999999;
        int p;
        for (int i = 0; i < 10; i++) {
            if (dp[i][i] == 1 << 28) continue;

            int sum = 0;

            for (int j = 0; j < 10; j++) {
                if (dp[i][j] != 1 << 28) sum += dp[i][j];
            }

            if (ans > sum) {
                ans = sum;
                p = i;
            }
        }

        cout << p << " " << ans << endl;
    }

    return 0;
}
