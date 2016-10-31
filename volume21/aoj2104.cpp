#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> v(N);
        for (auto& i : v) cin >> i;
        int ans = v[N-1] - v[0];
        vector<int> sub;
        for (int i = 1; i < N; i++) {
            sub.push_back(v[i] - v[i-1]);
        }

        sort(sub.begin(), sub.end());

        int c = 1;
        while (c + 1 <= N && c < K) {
            ans -= sub[N-c-1];
            c++;
        }

        cout << ans << endl;
    }

    return 0;
}
