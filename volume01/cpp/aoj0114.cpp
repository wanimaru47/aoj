#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    int a, b, c;
    int m, n, p;
    while (cin >> a >> m >> b >> n >> c >> p, a || b || c || m || n || p) {
        int c1 = 1, c2 = 1, c3 = 1;
        int x = a % m;
        int y = b % n;
        int z = c % p;

        while (x != 1) {
            c1++;
            x = (a * x) % m;
        }
        while (y != 1) {
            c2++;
            y = (b * y) % n;
        }
        while (z != 1) {
            c3++;
            z = (c * z) % p;
        }

        int c = 2;
        map<int,int> dp;
        while (c1 > 1) {
            int count = 0;
            while (c1 % c == 0) {
                count++;
                c1 /= c;
            }
            if (count) {
                dp[c] = max(dp[c], count);
            }
            c++;
        }
        c = 2;
        while (c2 > 1) {
            int count = 0;
            while (c2 % c == 0) {
                count++;
                c2 /= c;
            }
            if (count) {
                dp[c] = max(dp[c], count);
            }
            c++;
        }
        c = 2;
        while (c3 > 1) {
            int count = 0;
            while (c3 % c == 0) {
                count++;
                c3 /= c;
            }
            if (count) {
                dp[c] = max(dp[c], count);
            }
            c++;
        }

        ll ans = 1LL;
        for (auto i : dp) {
            ans *= pow((ll)i.first, (ll)i.second);
        }

        cout << ans << endl;
    }

    return 0;
}
