#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        vector<int> v(n+1);
        for (auto& i : v) cin >> i;

        int ans = 0;
        for (int i = 0; i < n+1; i++) {
            auto d = v;
            d.erase(d.begin() + i);
            vector<int> sub(n-1);
            for (int j = 0; j < n-1; j++) {
                sub[j] = d[j+1] - d[j];
            }
            bool flag = true;
            for (int j = 0; j < n-2; j++)
                if (sub[j+1]-sub[j]) flag = false;
            if (flag) ans = v[i];
        }

        cout << ans << endl;
    }

    return 0;
}
