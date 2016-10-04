#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> v(N);
        for (auto& i : v) cin >> i;

        int x = 0, y = 0;
        for (int i = 1; i < N; i++) {
            if (v[i] - v[i-1] >= 0) x = max(x, v[i]-v[i-1]);
            else y = min(y, v[i]-v[i-1]);
        }

        cout << x << " " << abs(y) << endl;
    }

    return 0;
}
