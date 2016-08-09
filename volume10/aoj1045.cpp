#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<int> v(N);
        int ans = 1 << 28;
        for (auto& i : v) cin >> i;
        for (int i = 1; i < (1<<N)-1; i++) {
            int A = 0, B = 0;
            for (int j = 0; j < N; j++)
                if (i&(1<<j)) A+=v[j];
                else B+=v[j];
            ans = min(ans, abs(A-B));
        }
        cout << ans << endl;
    }

    return 0;
}
