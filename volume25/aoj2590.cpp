#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, Q;
    while (cin >> N >> M >> Q, N || M || Q) {

        vector<string> S(2*Q+1), B(2*Q+1);
        vector<vector<int>> D(2*Q+1, vector<int>(M));

        string str;

        for (int i = 0; i < M; i++) {
            B[0] += '0';
            str += '1';
        }

        for (int i = 1; i <= Q; i++) {
            cin >> S[i-1] >> B[i];

            for (int j = 0; j < N; j++) {
                S[i+Q-1] += (S[i-1][j] == '0' ? '1' : '0');
            }

            for (int j = 0; j < M; j++) {
                if (B[i-1][j] != B[i][j]) {
                    D[i-1][j] = 1;
                } else {
                    D[i+Q-1][j] = 1;
                }
            }
        }

        vector<set<int>> ans(M);
        if (Q == 0) {
            if (N == 1) {
                for (auto &i : ans) i.insert(0);
            }
        } else {
            for (int i = 0; i < N; i++) {
                auto tmp = str;

                for (int j = 0; j < 2*Q; j++) {
                    if (S[j][i] == '0') continue;
                    for (int k = 0; k < M; k++) {
                        if (D[j][k] == 0) tmp[k] = '0';
                    }
                }

                for (int j = 0; j < M; j++) {
                    if (tmp[j] == '1') ans[j].insert(i);
                }
            }
        }

        for (int i = 0; i < M; i++) {
            if (ans[i].size() != 1) cout << '?';
            else if (*(ans[i].begin()) < 10) cout << *(ans[i].begin());
            else cout << (char)('A' + *(ans[i].begin()) - 10);
        }
        cout << endl;
    }

    return 0;
}
