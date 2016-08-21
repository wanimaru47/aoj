#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int x, y, b, p;
        cin >> x >> y >> b >> p;
        int sum = x * b + y * p;
        if (b >= 5 && p >= 2) sum = sum * 8 / 10;
        else {
            int tmp = x * max(b, 5) + y * max(p, 2);
            tmp = tmp * 8 / 10;
            sum = min(tmp, sum);
        }
        cout << sum << endl;
    }

    return 0;
}
