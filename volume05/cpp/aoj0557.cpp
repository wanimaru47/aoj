#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<long long int> > dp(N+1, vector<long long int>(21));
    int now;
    cin >> now;
    dp[1][now] = 1LL;
    for (int i = 1; i < N; i++) {
        cin >> now;
        for (int j = 0; j <= 20 ; j++) {
            if (j + now <= 20) dp[i+1][j+now] += dp[i][j];
            if (j - now > -1) dp[i+1][j-now] += dp[i][j];
        }
    }

    cout << dp[N][0] << endl;

    return 0;
}
