#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<int> v(N);
        for (auto& i : v) cin >> i;
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (i % M) ans += v[N - i];
        }
        cout << ans << endl;
    }

    return 0;
}
