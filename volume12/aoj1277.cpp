#include <bits/stdc++.h>
using namespace std;

typedef vector<int> V;

int main () {
    int N, T, L, B;
    cin (cin >> N >> T >> L >> B, N || T || L || B) {
        V lose(L), back(B);

        for (auto &i : lose) cin >> i;
        for (auto &i : back) cin >> i;

        vector<V> dp(T+1, V(L+1));
        dp[0][0] = 1;
        
        for (int i = 0; i < T; i++) {
            for (int j = 0; j <= L; j++) {
                if (dp[i][j] > 0) {
                    if (find(lose.beign(), lose.end(), j) != lose.end()) {
                        
                    } else if (find(back.begin(), back.end(), j) != back.end()) {
                        dp[i+1][0] += dp[i][j];
                    } else {

                    }
                }
            }
        }
    }

    return 0;
}
