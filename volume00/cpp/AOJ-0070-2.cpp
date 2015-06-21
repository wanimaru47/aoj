#include <iostream>
using namespace std;

int dp[1 << 10][331];
int n, s;

int dfs (int t, int sum, int k) {
    if (t == 0) return sum == s ? 1 : 0;
    if (s < sum) return 0;
    if (dp[t][s-sum] >= 0) return dp[t][s-sum];
    int res = 0;
    for (int i = 0; i < 10; i++) {
        if ((t & (1 << i)) > 0) {
            res += dfs(t-(1<<i), sum + i * k, k-1);
        }
    }

    return dp[t][s-sum] = res;
}

int main ()
{
    for (int i = 0; i < (1 << 10); i++) {
        for  (int j = 0; j <= 330; j++) {
            dp[i][j] = -1;
        }
    }
    while (cin >> n >> s) {
        if (s > 330) {
            cout << 0 << endl;
            continue;
        }
        int res = 0;
        for (int i = 1; i < (1 << 10); i++) {
            int t = i, count = 0;
            while (t) {
                count += t % 2; t /= 2;
            }
            if (n == count) res += dfs(i,0,count);
        }
        cout << res << endl;
    }
    
    return 0;
}
