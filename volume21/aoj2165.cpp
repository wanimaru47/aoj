#include <bits/stdc++.h>
using namespace std;

const double INF = (double)(1 << 28);
const int MOD = 256;
const double EPS = 1e-10;

int main () {
    int n;
    while (cin >> n, n) {
        vector<int> I(n);
        for (auto &i : I) cin >> i; 

        double H = INF;
        int S, A, C;
        for (int s = 0; s < 16; s++) {
            for (int a = 0; a < 16; a++) {
                for (int c = 0; c < 16; c++) {
                    vector<int> o(MOD, 0);
                    int r = s;
                    for (int i = 0; i < n; i++) {
                        r = (r * a + c) % MOD;
                        o[(r + I[i]) % MOD]++;
                    }
                    double h = 0.;
                    for (auto i : o) {
                        if (i > 0) h -= ((double)i / n) * log((double)i / n);
                    }
                    if (h + EPS < H) {
                        H = h, S = s, A = a, C = c;
                    }
                }
            }
        }
        cout << H << endl;
        cout << S << " " << A << " " << C << endl;
    }

    return 0;
}
