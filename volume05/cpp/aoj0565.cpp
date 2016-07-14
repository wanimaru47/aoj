#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> P(3), D(2);
    for (auto& i : P) cin >> i;
    for (auto& i : D) cin >> i;

    int ans = 1 << 28;
    for (auto i : P) {
        for (auto j : D) {
            ans = min(ans, i + j - 50);
        }
    }

    cout << ans << endl;
}
