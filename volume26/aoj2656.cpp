#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, D, ta, tb, da, db;
    cin >> T >> D >> ta >> tb >> da >> db;

    double res = 10000;
    for (int i = 0; i <= D / da; i++) {
        for (int j = 0; j <= D / db; j++) {
            if (da * i + db * j > D) continue;
            if (i == j && i == 0) continue;
            res = min(res, fabs((double)T - (double)(ta * da * i + tb * db * j) / (double)(da * i + db * j)));
        }
    }
    
    printf("%.8f\n", res);
    
    return 0;
}
