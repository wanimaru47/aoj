#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, L;
    while (cin >> N >> M >> L, N || M || L) {
        int Q; cin >> Q;
        vector<int> safe(N + M + L, 2);
        vector<int> I(Q), J(Q), K(Q);
        for (int f, q = 0; q < Q; q++) {
            cin >> I[q] >> J[q] >> K[q] >> f;
            I[q]--;
            J[q]--;
            K[q]--;
            if (f) safe[I[q]] = safe[J[q]] = safe[K[q]] = 1;
        }

        for (int q = 0; q < Q; q++) {
            if (safe[I[q]] == 2 && safe[J[q]] == 1 && safe[K[q]] == 1) safe[I[q]] = 0;
            if (safe[J[q]] == 2 && safe[I[q]] == 1 && safe[K[q]] == 1) safe[J[q]] = 0;
            if (safe[K[q]] == 2 && safe[I[q]] == 1 && safe[J[q]] == 1) safe[K[q]] = 0;
        }

        for (auto i : safe) cout << i << endl;
    }

    return 0;
}
