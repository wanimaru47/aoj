#include <bits/stdc++.h>
using namespace std;

int main ()
{
    double r;
    int n;
    while (cin >> r >> n, r || n) {
        vector<double> height(21 * 2 + 1, 0);
        for (int i = 0; i < n; i++) {
            int x1, x2;
            double h;
            cin >> x1 >> x2 >> h;
            for (int j = x1; j < x2; j++) {
                height[j + 21] = max(height[j + 21], h);
            }
        }

        double res = 20. + r;
        for (int i = 0; i < 21 * 2 + 1; i++) {
            if (abs(i - 21) >= r) continue;
            double low = min(height[i-1], height[i]);
            double C = low * low + abs(i - 21) * abs(i - 21) - r * r;
            double ret = low - sqrt(pow(low,2) - C) + r;
            res = min(res, ret);
        }

        printf("%.4f\n", res);
    }

    return 0;
}
