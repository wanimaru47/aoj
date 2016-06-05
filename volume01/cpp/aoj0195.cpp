#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5);
    while (1) {
        int a, b;
        cin >> a >> b;
        if (!a && !b) break;
        v[0] = a + b;
        for (int i = 1; i < 5; i++) {
            cin >> a >> b;
            v[i] = a + b;
        }

        int ans = 0, idx;
        for (int i = 0; i < 5; i++) {
            if (ans < v[i]) ans = v[i], idx = i;
        }

        cout << (char)('A' + idx) << " " << ans << endl;
    }

    return 0;
}
