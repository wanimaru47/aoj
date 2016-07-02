#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> temp(N);
    for (auto& i : temp) cin >> i;
    vector<int> A(M), B(M), C(M);
    for (int i = 0; i < M; i++)
        cin >> A[i] >> B[i] >> C[i];

    int dp[N+1][M];
    for (int i = 0; i < N + 1; i++)
        for (int j = 0; j < M; j++) dp[i][j] = -100000;

    for (int i = 0; i < M; i++) {
        if (temp[0] < A[i] || B[i] < temp[0]) continue;
        dp[0][i] = 0;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i] < A[j] || B[j] < temp[i]) continue;
            for (int k = 0; k < M; k++) {
                dp[i][j] = max(dp[i][j], dp[i-1][k] + abs(C[j] - C[k]));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++)
        ans = max(dp[N-1][i], ans);

    cout << ans << endl;

    return 0;
}
