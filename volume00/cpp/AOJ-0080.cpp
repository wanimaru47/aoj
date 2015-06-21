#include <iostream>
#include <cstdio>
#include <cmath>
#define EQ(a,b) (abs(a - b) < 0.00001 * b)
using namespace std;

int main ()
{
    double q;
    while (cin >> q, q >= 0) {
        double p  = q / 2;
        while (!EQ((p * p * p),q)) {
            p = p - ( ((p * p * p) - q) / (3 * p * p) );
        }
        printf("%.6f\n", p);
    }

    return 0;
}
