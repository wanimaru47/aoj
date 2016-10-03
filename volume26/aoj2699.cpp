#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, E;
    while (cin >> D >> E, D && E) {
        double ans = 1e9;
        for (int i = 0; i <= D; i++) {
            ans = min(ans, abs(sqrt(i * i + (D - i) * (D - i)) - E));
        }
        printf("%.12f\n", ans);
    }

    return 0;
}
