#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> s(N), l(N), p(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> l[i] >> p[i];
    }

    vector<int> dp(394, -1);
    dp[0] = 0;

    int len = dp.size();
    for (int i = 0; i < 394; i++) {
        if (dp[i] < 0) continue;
        for (int j = 0; j < N; j++) {
            for (int k = s[j]; k <= l[j]; k++) {
                if (i + k < len) dp[i + k] = max(dp[i + k], dp[i] + p[j]);
            }
        }
    }

    int M;
    cin >> M;

    vector<int> m(M);
    bool flag = true;
    for (int i = 0; i < M; i++) {
        cin >> m[i];
        if (dp[m[i]] < 0) flag = false;
    }
    if (flag) {
        for (auto i : m) cout << dp[i] << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
