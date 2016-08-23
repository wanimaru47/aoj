#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<int> v(N);
        for (auto& i : v) cin >> i;
        int med = N / 2;
        sort(v.begin(), v.end());
        int ans = -1;
        for (int i = 0; i < N; i++) {
            if (i + med < N && v[i] == v[i+med]) {
                ans = v[i];
                break;
            }
        }
        if (ans < 0) cout << "NO COLOR" << endl;
        else cout << ans << endl;
    }

    return 0;
}
