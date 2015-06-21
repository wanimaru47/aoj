#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    while (cin >> N, N) {
        vector<vector<bool> > v(N, vector<bool>(33, false));
        vector<vector<set<int> > > dp(N, vector<set<int> >(33));
        for (int i = 0; i < N; i++) {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                int tmp;
                cin >> tmp;
                v[i][tmp] = true;
                if (j == 0) dp[i][tmp].insert(i);
            }
        }

        bool flag = true;
        int res = 0;
        for (int i = 1; flag && i <= 31; i++) {
            set<int> count;
            for (int j = 0; j < N; j++) {
                if (v[j][i]) count.insert(dp[j][i].begin(), dp[j][i].end());
                if (dp[j][i].size() == N) res = i - 1, flag = false;
            }
            for (int j = 0; flag && j < N; j++)
                if (v[j][i]) dp[j][i + 1].insert(count.begin(), count.end());
                else dp[j][i + 1].insert(dp[j][i].begin(), dp[j][i].end());
        }

        /*
        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= 30; j++) {
                cout << dp[i][j].size() << " ";
            }
            cout << endl;
        }
        */

        cout << (res == 0 ? -1 : res) << endl;
    }

    return 0;
}
