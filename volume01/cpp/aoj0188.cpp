#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<int> v(N);
        for (auto& i : v) cin >> i;

        int x;
        cin >> x;
        int l = 0, r = N - 1;

        int count = 0;
        while (true) {
            int m = (r + l) / 2;
            count++;
            if (v[m] == x) break;

            if (v[m] < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }

            if (l > r) break;
        }

        cout << count << endl;
    }

    return 0;
}
