#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, m;
    cin >> n >> m;
    vector<double> R(n), G(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i] >> G[i] >> B[i];
    }

    double res = 0.0;
    for (int i = 1; i < 1 << n; i++) {
        int bits = 0;
        int s = i;
        while (s) {
            if (s % 2) bits++;
            s /= 2;
        }
        if (bits == m) {
            double ret = 0.0;
            int k = 0;
            for (int j = 0; k < bits; j++) {
                if (i&(1 << j)) {
                    k++;
                    for (int l = j + 1; l < n; l++) {
                        if (i & (1 << l)) {
                            ret += pow(R[j] - R[l], 2) + pow(G[j] - G[l], 2) + pow(B[j] - B[l], 2);
                        }
                    }
                }
            }
            res = max(ret, res);
            cout << i << " " << ret << endl;
        }
    }

    printf("%.8f\n", res);

    return 0;
}
