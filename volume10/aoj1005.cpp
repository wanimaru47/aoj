#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<vector<int> > d(N, vector<int>(N));
        for (auto& i : d) for (auto& j : i) cin >> j;

        vector<int> r(N, 1 << 28), l(N);
        for (int i = 0; i < N; i++) {
            for (auto j : d[i]) r[i] = min(r[i], j);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                l[i] = max(l[i], d[j][i]);
            }
        }

        int ans = -1;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (l[i] == r[j]) ans = max(ans, l[i]);

        if (ans > -1) cout << ans << endl;
        else cout << 0 << endl;
    }

    return 0;
}
