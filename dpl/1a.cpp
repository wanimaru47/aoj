#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
     int n, m, ans = 0;
     cin >> n >> m;
     
     int coin[m], dp[n + 1];
     memset(dp, 1000000, sizeof(dp));
     for (int i = 0; i < m; i++) {
	  cin >> coin[i];
	  dp[coin[i]] = 1;
     }
     sort(coin, coin + m);
     for (int i = 1; i < n; i++)
	  for (int j = 0; j < m; j++)
	       if (i + coin[j] <= n) dp[i + coin[j]] = min(dp[i + coin[j]],dp[i] + 1);
     
     cout << dp[n] << endl;
     
     return 0;
}
