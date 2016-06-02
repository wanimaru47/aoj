#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 28;
int N;

int create_next(vector<int>& next, vector<int>& p, int now) {
    if (!p[now]) return next[now] = now;
    if (next[now] == -2) return next[now] = INF;
    if (next[now] > -1) return next[now];
    next[now] = -2;
    int now_ = now + p[now];
    if (now_ < 0) now_ = 0;
    else if (now_ >= N) now_ = N - 1;
    return next[now] = create_next(next, p, now_);
}

int main() {
    cin >> N;
    vector<int> p(N);
    for (auto &i : p) cin >> i;

    vector<int> dp(N, INF);
    dp[0] = 0;
    vector<int> next(N, -1);
    for (int i = 0; i < N; i++) {
        if (!p[i]) next[i] = i;
        else create_next(next, p, i);
    }

    priority_queue<int, vector<int>, greater<int> > que;
    que.push(0);

    while (que.size()) {
        int now = que.top(); que.pop();

        for (int  i = 1; i <= 6; i++) {
            int nx = now + i;
            if (nx >= N) nx = N - 1;
            nx = next[nx];

            if (nx == INF) continue;
            if (dp[now] + 1 < dp[nx]) {
                dp[nx] = dp[now] + 1;
                que.push(nx);
            }
        }
    }

    cout << dp[N-1] << endl;

    return 0;
}
