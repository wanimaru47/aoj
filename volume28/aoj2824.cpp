#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D, L;
    while (cin >> N >> D >> L, N || D || L) {
        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            int l;
            cin >> l;
            if (l >= L) v[i]++, v[min(N-1, i+D)]--;
        }

        int count = 0;
        int ans = 0;
        for (int i = 0; i < N-1; i++) {
            count += v[i];
            if (count > 0) ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
