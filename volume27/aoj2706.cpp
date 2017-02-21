#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, q;
    cin >> p >> q;

    int g = q / __gcd(p, q);
    set<int> s;
    for (int i = 1; i <= sqrt(g); i++) {
        if (g % i == 0) {
            s.insert(i);
            s.insert(g / i);
        }
    }
    int ans = 1;
    for (auto i : s) {
        bool flag = true;
        for (int j = 2; flag && j <= sqrt(i); j++) {
            if (i % j == 0) flag = false;
        }

        if (flag) ans *= i;
    }

    cout << ans << endl;
    
    return 0;
}
