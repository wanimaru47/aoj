#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main ()
{
    int a, b, c;
    while (cin >> a >> b >> c) {
        int sum1 = a + b, sum2 = c;
        vector<bool> v(11, true);
        v[a] = v[b] = v[c] = false;
        int res1 = 0, res2 = 0;
        for (int i = 0; i < 11; i++) {
            if (v[i]) {
                for (int j = 1; j < 11; j++) {
                    for (int k = 0; k < 11; k++) {
                        if (v[j] && v[k] && k != j && i != j && i != k) {
                            if (sum1 + j <= 20) res1++;
                            else res2++;
                        }
                    }
                }
            }
        }
        if ((double)res1 / (double)(res2 + res1) >= 0.50) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
