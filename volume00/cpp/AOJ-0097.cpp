#include <bits/stdc++.h>
using namespace std;

map<int,long long int> dp[111][111];

int main() {
    int N, S;
    while (cin >> N >> S, N || S) {
        for (int i = 0; i < 111; i++) 
            for (int j = 0; j < 111; j++) dp[i][j].clear();
        dp[0][0][0] = 1;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= N; j++) {
                for (auto k : dp[i][j]) {
                    dp[i + 1][j + 1][k.first + i] += k.second;
                    dp[i + 1][j][k.first] += k.second;
                }
            }
        }

        cout << dp[101][N][S] << endl;
    }

    return 0;
}
