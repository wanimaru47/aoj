#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        int ans = -1;
        int p;
        for (int i = 0; i < N; i++) {
            int t, d, c;
            cin >> t >> d >> c;
            if (ans < d + c) ans = d + c, p = t;
        }
        cout << p << " " << ans << endl;
    }

    return 0;
}
