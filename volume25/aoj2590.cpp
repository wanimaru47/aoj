#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;

int main() {
    int N, M, Q;
    while (cin >> N >> M >> Q, N + M + Q) {
        vector<string> S(Q + 1), B(Q + 1);
        for (int i = 0; i < M; i++) B[0] += '0';
        for (int i = 1; i <= Q; i++) {
            cin >> S[i-1] >> B[i];
        }

        mat b(Q, vec(M, 0));
        for (int i = 1; i <= Q; i++) {
            for (int j = 0; j < M; j++) {
                if (B[i][j] != B[i-1][j]) b[i - 1][j] = 1;
            }
        }

        // for (int i = 0; i < Q; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << b[i][j];
        //     } cout << endl;
        // }

        mat dp2(N, vec(M, 1));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < Q; j++) {
                if (S[j][i] == '1') {
                    for (int k = 0; k < M; k++) {
                        dp2[i][k] *= b[j][k];
                    }
                }
            }
        }

        mat dp(M, vec(N, 1));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < Q; j++) {
                if (b[j][i]) {
                    for (int k = 0; k < N; k++) {
                        dp[i][k] *= (S[j][k] == '1' ? 1 : 0);
                    }
                }
            }
        }

        vector<set<int>> count2(M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (dp2[i][j]) count2[j].insert(i);
            }
        }

        vector<set<int>> count(M);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (dp[i][j]) count[i].insert(j);
            }
        }

        vector<char> dis(M);
        vec dd(M);
        for (int i = 0; i < M; i++) {
            int num = -1;
            if (count[i].size() == 1) {
                num = *(count[i].begin());
            } else if (count2[i].size() == 1) {
                num = *(count2[i].begin());
            }
            if (num < 0) dis[i] = '?';
            else if (num < 10) dis[i] = '0' + num;
            else dis[i] = 'A' + num - 10;
            dd[i] = num;
        }
        vec ls;
        for (int i = 0; i < N; i++) {
            if (find(dd.begin(), dd.end(), i) == dd.end()) ls.push_back(i);
        }
        if (ls.size() == 1) {
            for (int i = 0; i < M; i++) if (dd[i] < 0) {
                if (ls[0] < 10) dis[i] = '0' + ls[0];
                else dis[i] = 'A' + ls[0] - 10;
            }
        }
        for (auto i : dis) cout << i;
        cout << endl;
    }
    
    return 0;
}
