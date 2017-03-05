#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;

    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int x = v[i] * v[j];
            int k = x % 10; k++;
            bool flag = true;
            while (x) {
                if ((x % 10) + 1 != k) flag = false;
                k = x % 10;
                x /= 10;
            }
            if (flag) ans = max(ans, v[i]*v[j]);
        }
    }

    cout << ans << endl;

    return 0;
}
