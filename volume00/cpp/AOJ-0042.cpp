#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

typedef map<int, int> M;

const int MAX_N = 1000;
const int MAX_W = 10000;

int dp[MAX_N + 1][MAX_W + 1];

int main()
{
    int times = 1;
    while (1) {
        int lim;
        cin >> lim;
        if (lim == 0) break;
        int n;
        cin >> n;
        int v[MAX_N], w[MAX_N];
        for (int i = 0; i < n; i++)
            scanf("%d,%d", &v[i], &w[i]);

        M m;
        for (int i = n -1; i >= 0; i--) {
            for (int j = 0; j <= lim; j++) {
                if (j < w[i]) dp[i][j] = dp[i + 1][j];
                else dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
                if (m[dp[i][j]] == 0 || m[dp[i][j]] > j ) m[dp[i][j]] = j; 
            }
        }
        cout << "Case " << times << ":" << endl << dp[0][lim] << endl << m[dp[0][lim]] << endl;
        times++;
    }
    
    return 0;
}
