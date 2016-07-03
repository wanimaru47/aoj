#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int> > C(10);
    for (int i = 0; i < N; i++) {
        int c, g;
        cin >> c >> g;
        C[g-1].push_back(c);
    }


    for (auto& c : C) {
        sort(c.begin(), c.end(), greater<int>());
    }

    for (auto& c : C) {
        for (int i = 1; i < c.size(); i++) c[i] += c[i-1];
        for (int i = 1, len = c.size(); i < len; i++)
            c[i] += i * (i + 1);
        c.insert(c.begin(), 0);
    }

    vector<vector<int> > dp(1 << 10, vector<int>(K + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < (1 << 10) - 1; i++) {
        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) continue;
            int l = 0;
            while (l <= K && dp[i][l] > -1) {
                for (int k = 0; k + l <= K && k < C[j].size(); k++) {
                    dp[i | (1 << j)][k + l] = max(dp[i | (1 << j)][l + k], dp[i][l] + C[j][k]);
                }
                l++;
            }
        }
    }

    cout << dp[(1 << 10) - 1][K] << endl;

    return 0;
}
