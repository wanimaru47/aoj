#include <bits/stdc++.h>
using namespace std;

int p, q, a, n;
double D;
typedef pair<int,int> P;

int dfs (int sum, int mul, int last, int count) {
    double d = (double)sum / mul;
    if (count > n) return 0;
    if (mul > a) return 0;
    if (d > D) return 0;
    if (d == D) return 1;


    int ret = 0;
    for (int i = last; i <= a / mul; i++) {
        ret += dfs(sum * i + mul, mul * i, i, count+1);
    }

    return ret;
}

int main ()
{
    while (cin >> q >> p >> a >> n, q + p + a + n) {
        D = (double)q / p;
        cout << dfs(0, 1, 1, 0) << endl;
    }

    return 0;
}
