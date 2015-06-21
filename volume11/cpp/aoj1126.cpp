#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int main ()
{
    int n, m;
    while (cin >> m >> n, n || m) {
        vector<vector<char> > v (n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char str;
                cin >> str;
                if ('0' <= str && str <= '9') {
                    v[i][j] = str;
                }
            }
        }

        vector<vector<string> > dp(n, vector<string>(m, ""));

        string res = "";
        
        for (int i = 0; i < m; i++) {
            if (v[0][i] != '#') {
                if (v[0][i] == '0') {
                    if (i > 0 && dp[0][i-1].size() > 0) {
                        dp[0][i] = dp[0][i-1] + v[0][i]; 
                    } 
                } else {
                    if (i > 0) {
                        dp[0][i] = dp[0][i-1] + v[0][i]; 
                    } else {
                        dp[0][i] = v[0][i];
                    }
                }
            }
            if (res.size() == dp[0][i].size()) {
                res = max(res, dp[0][i]);
            } else {
                res = res.size() > dp[0][i].size() ? res : dp[0][i];
            }
        }

        for (int i = 1; i < n; i++) {
            if (v[i][0] != '#') {
                if (v[i][0] == '0') {
                    if (dp[i-1][0].size() > 0) dp[i][0] = dp[i-1][0] + v[i][0]; 
                } else {
                    dp[i][0] = dp[i-1][0] + v[i][0];
                }
            }
            if (res.size() == dp[i][0].size()) {
                res = max(res, dp[i][0]);
            } else {
                res = res.size() > dp[i][0].size() ? res : dp[i][0];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (v[i][j] != '#') {
                    string s1;
                    if (dp[i-1][j].size() > 0 || v[i][j] != '0') s1 = dp[i-1][j] + v[i][j];
                    string s2;
                    if (dp[i][j-1].size() > 0 || v[i][j] != '0') s2 = dp[i][j-1] + v[i][j];

                    if (s1.size() == s2.size()) {
                        dp[i][j] = max(s1, s2);
                    } else {
                        dp[i][j] = s1.size() > s2.size() ? s1 : s2;
                    }
                    if (res.size() == dp[i][j].size()) {
                        res = max(res, dp[i][j]);
                    } else {
                        res = res.size() > dp[i][j].size() ? res : dp[i][j];
                    }
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}
