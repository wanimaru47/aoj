#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<int> v(N), m(N);
        for (int i = 0; i < M; i++) {
            int s, k;
            cin >> s >> k;
            if (k == 1) {
                int t;
                cin >> t;
                v[t-1] += s;
                m[t-1] += s;
            } else {
                for (int j = 0; j < k; j++) {
                    int t;
                    cin >> t;
                    v[t-1] += s;
                }
            }
        }

        int first = -1, second = -1, idx, idy;
        for (int i = 0; i < N; i++) {
            if (first < v[i]) {
                second = first;
                idy = idx;
                first = v[i];
                idx = i;
            } else if (second < v[i]) {
                second = v[i];
                idy = i;
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (idx == i) {
                ans = max(ans, second - m[i]);
            } else {
                ans = max(ans, first - m[i]);
            }
        }

        cout << ans+1 << endl;
    }

    return 0;
}
