#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

const int INF = 1 << 28;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vec B(N), R(M);
        for (auto &i : B) cin >> i;
        for (auto &i : R) cin >> i;
        
        vector<set<int>> m(N + M);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (__gcd(B[i], R[j]) > 1) {
                    m[i].insert(j + N);
                    m[j + N].insert(i);
                }
            }
        }

        int res = 0;

        while (1) {
            int min_i = INF;
            int I;
            for (int i = 0; i < N; i++) {
                if (m[i].size() > 0 && min_i > m[i].size()) {
                    min_i = m[i].size();
                    I = i;
                }
            }

            if (min_i == INF) break;

            int min_j = INF;
            int J;
            for (auto j : m[I]) {
                if (m[j].size() > 0 && m[j].size() < min_j) {
                    min_j = m[j].size();
                    J = j;
                }
            }

            m[I].clear();
            
            if (min_j != INF) {
                res++;
                m[J].clear();
                // cout << I << ":" << B[I] << " " << J - N << ":" << R[J - N] << endl;
            }
        }

        cout  << res << endl; 
    }

    return 0;
}
