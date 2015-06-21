#include <iostream>
#include <cstdio>
using namespace std;

int dp[22][11][156];

int main ()
{
    int n, m, p;

    for (int i = 0; i <= 20; i++) {
        dp[i][1][i] = 1;
    }

    for (int i = 1; i <= 20; i++) {
        for (int k = 1; k <= 155; k++) {
            for (int j = 1; j <= 10; j++) {
                if (dp[i][j][k]) {
                    dp[i + 1][j][k] += dp[i][j][k];
                    if (j < 10 && k + i + 1 <= 155) 
                        dp[i + 1][j + 1][k + i + 1] += dp[i][j][k];
                }
            }
        }
    }

    while (cin >> n >> m >> p, (n || m || p)) {
        cout << dp[n][m][p] << endl;
    }
    
    return 0;
}
