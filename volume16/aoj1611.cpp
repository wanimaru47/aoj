#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<int> v(N);
        for (auto& i : v) cin >> i;

        vector<vector<int>> dp(N+1, vector<int>(N));
        for (int i = 0; i < N; i++) {
            if (abs(v[i] - v[i+1]) < 2) {
                dp[2][i] = 1;
            }
        }
        for (int i = 4; i <= N; i += 2) {
            for (int j = 0; j + i <= N; j++) {
                if (dp[i-2][j+1] && abs(v[j] - v[j + i - 1]) < 2) {
                    dp[i][j] = 1;
                } else {
                    for (int k = 2; j + k < j + i; k += 2) {
                        if (dp[k][j] && dp[i - k][j + k]) {
                            dp[i][j] = 1;
                        }
                    }
                }
            }
        }

        vector<int> sum(N+1);
        for (int i = 0; i < N; i++) {
            if (i) sum[i] = max(sum[i], sum[i-1]);
            for (int j = 2; j <= N; j += 2) {
                if (dp[j][i]) {
                    sum[i+j] = max(sum[i+j], sum[i] + j);
                }
            }
        }

        cout << max(sum[N-1], sum[N]) << endl;
    }

    return 0;
}
