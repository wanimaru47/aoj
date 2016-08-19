#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, S;
    while (cin >> N >> S, N || S) {
        vector<int> d(N);
        for (auto& i : d) cin >> i;
        sort(d.begin(), d.end());

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int sub = S - d[i] + 1;
            if (sub <= d[i]) ans += N - 1 - i;
            else {
                int c = lower_bound(d.begin(), d.end(), sub) - d.begin();
                ans += N - c;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
