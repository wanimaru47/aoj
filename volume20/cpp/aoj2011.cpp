#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    while (cin >> N, N) {
        vector<vector<bool> > v(N, vector<bool>(33, false));
        vector<vector<long long> > dp(N, vector<long long>(33, 0));
        for (int i = 0; i < N; i++) {
            int m;
            cin >> m;
            dp[i][1] = 1LL << i;
            for (int j = 0; j < m; j++) {
                int tmp;
                cin >> tmp;
                v[i][tmp] = true;
            }
        }

        int res = 0;

        for (int k = 1; k <= 31; k++) {
            long long tmp = 0;
            for (int i = 0; i < N; i++) {
                if (v[i][k]) {
                    tmp |= dp[i][k];
                }
            }

            if ((1LL << N) - 1LL == tmp) {
                res = k;
                break;
            }

            for (int i = 0; i < N; i++) {
                if (v[i][k]) {
                    dp[i][k+1] |= tmp;
                } else {
                    dp[i][k+1] |= dp[i][k];
                }
            }
        }

        cout << (res == 0 ? -1 : res) << endl;
    }

    return 0;
}
