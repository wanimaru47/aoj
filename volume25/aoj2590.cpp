#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N, M, Q;
    while (cin >> N >> M >> Q, N + M + Q) {
        vector<ll> S(Q + 1), B(Q + 1);
        for (int i = 1; i <= Q; i++) {
            cin >> S[i] >> B[i];
        }

        vector<ll> s(Q), b(Q);
        for (int i = 0; i < Q; i++) {
            s[i] = S[i] & S[i+1];
            b[i] = B[i] & B[i+1];
        }

        vector<int> ans(40, -1);
    }
    
    return 0;
}
