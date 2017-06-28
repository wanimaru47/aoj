#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<set<int>> s[2];
    vector<bool> used(N);
    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        int len = s[0].size();
        s[0].push_back(set<int>());
        s[1].push_back(set<int>());
        int side = 0;
        queue<int> que[2];
        que[0].push(i);
        while (que[0].size()) {
            while (que[0].size()) {
                int num = que[0].front(); que[0].pop();
                s[side][len].insert(num);
                used[num] = true;
                for (auto j : v[num]) {
                    if (s[side][len].find(j) == s[side][len].end()) {
                        if (!used[j]) que[1].push(j);
                    } else {
                        cout << - 1 << endl;
                        return 0;
                    }
                }
            }
            que[0] = que[1];
            que[1] = queue<int>();
            side = !side;
        }
    }

    map<ll,ll> m;
    ll sub = 0;
    for (int i = 0; i < s[0].size(); i++) {
        m[(ll)max(s[0][i].size(), s[1][i].size()) - (ll)min(s[0][i].size(), s[1][i].size())]++;
        sub += (ll)min(s[0][i].size(), s[1][i].size());
    }

    vector<ll> dp(N+1, -1);
    dp[0] = 0;
    for (auto p : m) {
        ll x = p.first;
        ll count = p.second;
        for (ll i = 0; i < dp.size(); i++) {
            if (dp[i] >= 0) dp[i] = count;
            else if (i < x || dp[i - x] < 0) dp[i] = -1LL;
            else dp[i] = dp[i - x] - 1LL;
        }
    }

    ll ans = 0;
    for (ll i = 0; i <= N; i++) {
        if (dp[i] >= 0)
            ans = max(ans, (sub + i) * (N - sub - i) - M);
    }

    cout << ans << endl;

    return 0;
}
