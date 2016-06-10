#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

const int INF = 1 << 28;
int N, M;

bool check(vec& v, vec& t) {
    for (int i = 0; i < N; i++) {
        if (v[i] >= t[i]) return false;
    }

    return true;
}

void solve() {
    mat dp(10001, vec(N, 0));
    vec count(10001);
    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        dp[w][x-1]++;
        dp[w][y-1]++;
        count[w]++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10000; j++) {
            dp[j+1][i] += dp[j][i];
        }
    }

    for (int i = 0; i < 10000; i++) {
        count[i+1] += count[i];
    }

    int i = 0;
    int ans = INF;
    for (int j = 0; j <= 10000; j++) {
        if (!check(dp[i], dp[j])) continue;
        while (check(dp[i], dp[j])) {
            if (count[j] - count[i] >= N - 1) ans = min(ans, j - i - 1);
            i++;
        }
    }

    cout << (ans >= 10000 ? -1 : ans) << endl;
}

int main() {
    while (cin >> N >> M, N || M) solve();

    return 0;
}
