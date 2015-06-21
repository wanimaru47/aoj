#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, m;
    while (cin >> n >> m, n || m) {
        int MAX = 0;
        int d = 0;
        vector<int> v((int)(100 / m) + 1, 0);
        for (int i = 0; i < n; i++) {
            int num = 0;
            cin >> num;
            v[num / m]++;
            MAX = max(MAX, num / m);
            d = max(d, v[num / m]);
        }

        double res = 0;
        for (int i = 0; i < MAX; i++) {
            res += ((double)(v[i]) / d) * ((double)(MAX - i) / MAX);
        }

        res += 0.01;

        printf("%.8f\n", res);
    }

    return 0;
}
