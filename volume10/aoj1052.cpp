#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    while (cin >> N, N) {
        vector<ll> d(N), u(N);
        vector<bool> used(N, false);
        ll sum = 0;
        bool ans = true;
        for (int i = 0; i < N; i++) {
            cin >> d[i] >> u[i];
            sum += d[i];
        }

        while(true) {
            bool flag = false;
            for (auto i : used)
                if (!i) flag = true;

            if (!flag) break;
            else flag = false;

            ll sub = 0;
            for (int i = 0; i < N; i++) {
                if (used[i]) continue;
                if (u[i] >= sum) {
                    sub += d[i];
                    used[i] = true;
                    flag = true;
                }
            }
            if (!flag) {
                ans = false;
                break;
            }
            sum -= sub;
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
