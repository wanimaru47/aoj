#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int INF = 1 << 28;
int N;
void solve() {
    vector<string> str(N);
    for (auto& i : str) cin >> i;

    vector<bool> use(N, true);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && str[i].find(str[j]) != string::npos) use[j] = false;
        }
    }

    auto tmp_str = str;
    str.resize(0);
    for (int i = 0; i < N; i++) if (use[i]) str.push_back(tmp_str[i]);

    int n = str.size();
    mat num(n, vec(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 1, s1 = str[i].size(), s2 = str[j].size(); k < s1 && k < s2; k++) {
                if (string(str[i].end() - k, str[i].end()) == string(str[j].begin(), str[j].begin() + k))
                    num[i][j] = k;
            }
        }
    }

    mat dp(1 << n, vec(n, INF));
    for (int i = 0; i < n; i++) dp[1 << i][i] = str[i].size();
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j) == 0) continue;
            for (int k = 0; k < n; k++) {
                if (j == k || i & (1 << k)) continue;
                dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] - num[j][k] + (int)str[k].size());
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[(1 << n) - 1][i]);
    cout << ans << endl;
}

int main() {
    while (cin >> N, N) solve();

    return 0;
}
