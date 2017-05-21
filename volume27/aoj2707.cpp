#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll N, K;
    cin >> N >> K;

    ll ans = 0LL;
    for (int i = 0; i < N-1; i++) {
        ans += (ans / (K-1)) + 1;
    }
    cout << ans << endl;

    return 0;
}
