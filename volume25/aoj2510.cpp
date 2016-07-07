#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
template<typename T>
using vec = vector<T>;

int N;

void solve() {
    vec<P> p(N);
    for (auto &i : p) cin >> i.first >> i.second;
    sort(p.begin(), p.end());
    int sum = 0;
    for (int i = 0; i < N - 1; i++) sum += p[i].first;
    int sub = 0;
    if (sum < p[N-1].first) sub = p[N-1].first - sum;

    vector<map<int,bool> > dp(N);
    dp[0][0] = true;
    int m = 0;
    for (int i = 0; i < N; i++) {
        for (auto x : dp[i]) {
            if (x.first > sub) break;
            m = max(x.first, m);
            if (i == N - 1) continue;
            dp[i+1][x.first] = true;
            if (x.first + p[i].second <= sub) dp[i+1][x.first + p[i].second] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) ans += p[i].first + p[i].second;

    cout << ans + sub - m << endl;
}

int main() {
    while (cin >> N, N) solve();
    return 0;
}
