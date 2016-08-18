#include <bits/stdc++.h>
using namespace std;

int main() {
    int b, r, g, c, s, t;
    while (cin >> b >> r >> g >> c >> s >> t, b || r || g || c || s || t) {
        int count = 100;
        count += 15 * b;
        t -= 5 * b;
        count += 15 * r;
        t -= 3 * r;
        count += (5 * b + 3 * r) * 15;
        count += 7 * g;
        count += 2 * c;
        count -= 3 * (t - s) + 2 * (5 * b + 3 * r);

        cout << count << endl;
    }

    return 0;
}
