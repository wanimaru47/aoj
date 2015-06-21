#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main ()
{
    double dx = 0, dy = 0, x, y, t = 90.0;
    while (scanf("%lf,%lf", &x, &y), x || y) {
        dx += x * cos(t * M_PI / 180.0);
        dy += x * sin(t * M_PI / 180.0);
        
        t -= y;
    }

    cout << (int)dx << endl << (int)dy << endl;

    return 0;
}
