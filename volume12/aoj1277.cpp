#include <bits/stdc++.h>
using namespace std;

typedef vector<int> V;

int main () {
    int N, T, L, B;
    while (cin >> N >> T >> L >> B, N || T || L || B) {
        V lose(L,0), back(B,0);
        auto sum = pow(6.0,(double)T);

        for (int i = 0; i < L; i++) cin >> lose[i];
        for (int i = 0; i < B; i++) cin >> back[i];

        vector<V> dp(T+3, V(N+1));
        dp[0][0] = 1;
        
        for (int i = 0; i < T; i++) {
            for (int j = 0; j <= N; j++) {
                if (dp[i][j] > 0) {
                    for (int k = 1; k < 7; k++) {
                        int next = j + k <= N ? j + k : N * 2 - (j + k);
                        if (find(lose.begin(), lose.end(), next) != lose.end()) {
                            dp[i+2][next] += dp[i][j];
                        } else if (find(back.begin(), back.end(), next) != back.end()) {
                            dp[i+1][0] += dp[i][j];
                        } else {
                            dp[i+1][next] += dp[i][j];
                        }
                    }
                }
            }
        }

        for (int i = 0; i <= T; i++) {
            for (int j = 0; j <= N; j++) {
                cout << dp[i][j] << " ";
            } cout << endl;
        }

        cout << "# " << sum << endl;
        cout << ((double)dp[T][N] / sum) << endl;
    }

    return 0;
}
