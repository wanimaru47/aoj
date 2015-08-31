#include <bits/stdc++.h>
using namespace std;

typedef vector<int> V;
typedef vector<V> VV;

int main () {
    int n, m;

    while (cin >> n >> m, n + m) {
        V h1(n), h2(m), d(21), c(21);
        for (auto &i : h1) cin >> i;
        for (auto &i : h2) cin >> i;

        for (int i = 0; i < n; i++) {
            d[h1[i]]++;
            c[h1[i]]++;            
        }

        for (int i = 0; i < m; i++) {
            if (c[h2[i]] == 0) d[h2[i]]++;
            else c[h2[i]]--;
        }

        int res = 0;
        for (int i = 0; i < d.size(); i++) {
            res += d[i] * i;
        }

        cout << res << endl;
    } 
    return 0;
}
    
