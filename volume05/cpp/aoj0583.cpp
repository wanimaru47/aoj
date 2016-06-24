#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int m = 1 << 28;
    for (int i = 0; i < n; i++) cin >> v[i], m = min(m, v[i]);
    for (int i = 1; i <= m; i++) {
        bool flag = true;
        for (int j = 0; flag && j < n; j++) if (v[j] % i > 0) flag = false;
        if (flag) cout << i << endl;
    }

    return 0;
}
