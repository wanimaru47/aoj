#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    while (cin >> n >> m >> k, n || m || k) {
        vector<map<int,int> > dp(n+1);
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (auto &j : dp[i]) {
                for (int l = 1; l <= m; l++) {
                    dp[i+1][j.first + l] += j.second;
                }
            }
        }

        int sum = 0;
        int count = 0;
        for (auto i : dp[n]) {
            if (i.first - k <= 1) count += i.second;
            else count += i.second * (i.first - k);
            sum += i.second;
        }

        printf("%.9f\n", (double)count/sum);
    }

    return 0;
}
