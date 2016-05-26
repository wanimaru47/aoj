#include <bits/stdc++.h>
using namespace std;

int main() {
    double n; cin >> n;
    double ans = 2. * sqrt(n * n / 2.);
    if (n >= 1.) ans = max(ans, floor(n) + 1.);

    printf("%.12f\n", ans);

    return 0;
}
