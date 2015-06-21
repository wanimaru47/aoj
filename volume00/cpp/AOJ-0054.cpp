#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    long long t;
    double a, b, n;
    while (cin >> a >> b >> n) {
        double p = a / b - (int)(a / b);
        t = (long long)(p * pow(10.0, n));
        long long res = 0;
        for (int i = (int)n; i > 0; i--) {
            res += t % 10;
            t /= 10;
        }
        cout << res << endl;
    }

    return 0;
}
