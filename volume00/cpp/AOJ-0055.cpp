#include <iostream>
#include <cstdio>
using namespace std;

double c (double sum, double n, int t) {
    if (t >= 10) return sum;
    if ((t+1) % 2 == 1) {
        sum += n;
        n *= 2.0;
        return c(sum, n, t+1);
    } else {
        sum += n;
        n /= 3.0;
        return c(sum, n, t+1);
    }
}

int main ()
{
    double n;
    while (cin >> n) {
        printf("%.7f\n", c(0.0, n, 0));
    }

    return 0;
}
