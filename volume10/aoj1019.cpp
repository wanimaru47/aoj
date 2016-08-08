#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<int> d(M);
        for (auto& i : d) cin >> i;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int x; cin >> x;
                d[j] -= x;
            }
        }
        bool ans = true;
        for (auto i : d) {
            if (i < 0) ans = false;
        }
        cout << (ans ? "Yes" : "No") << endl;
    }

    return 0;
}
