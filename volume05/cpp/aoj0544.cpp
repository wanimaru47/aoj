#include <bits/stdc++.h>
using namespace std;

int N, M;

void solve() {
    vector<int> v(N), d(M);
    for (auto& i : v) cin >> i;
    for (auto& i : d) cin >> i;

    int start = 0;
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (start >= N) break;
        ans++;
        start = d[i] + start + v[d[i] + start];
    }

    cout << ans << endl;
}

int main() {
    while (cin >> N >> M, N || M) solve();
}
