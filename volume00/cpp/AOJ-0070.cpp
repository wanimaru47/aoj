#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <bitset>
using namespace std;

int n, s;
int dp[1 << 10][10000];

int c (int i, int sum, int t) {
    if (t == 0) return (sum == s ? 1 : 0);
    if (sum > s) return 0;
    if (dp[i][s-sum] >= 0) return dp[i][s-sum];
    int res = 0;
    for (int j = 0; j < 10; j++) {
        if ((i & (1 << j)) > 0 && c(i - (1 << j), sum + j * t, t-1)) res++;
    }
    return dp[i][s-sum] = res;
}

int main ()
{
    for (int i = 0; i < 1 << 10; i++)
        for (int j = 0; j < 10000; j++) 
            dp[i][j] = -1;

    while (cin >> n >> s) {
        int res = 0;        
        for (int i = 1; i < 1 << 10; i++) {
            int t = 0;
            for (int j = 0; j < 10; j++) 
                if ((i & (1 << j)) > 0) t++;
            if (t == n) res += c(i,0,t);
        }
        cout << res << endl;
    }

    return 0;
}
