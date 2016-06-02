#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 28;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (auto &i : p) cin >> i;

    vector<int> dp(N, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        if (dp[i] == INF) continue;
        for (int j = 1; j <= 6; j++) {
            int next = i + j;
            if (next < 0) next = 0;
            if (next >= N) next = N - 1;
            vector<bool> flag(N, false);
            flag[next] = true;
            bool cnt = false;
            int next_ = next + p[next];
            if (next_ < 0) next_ = 0;
            if (next_ >= N) next_ = N - 1;
            while(next != next_) {
                next = next_;
                if (flag[next]) {cnt = true; break;}
                flag[next] = true;
                next_ = next + p[next];
                if (next_ < 0) next_ = 0;
                if (next_ >= N) next_ = N - 1;
            }
            if (cnt) continue;
            if (next < 0) next = 0;
            if (next >= N) next = N - 1;

            dp[next] = min(dp[next], dp[i] + 1);
        }
    }

    cout << dp[N-1] << endl;

    return 0;
}
