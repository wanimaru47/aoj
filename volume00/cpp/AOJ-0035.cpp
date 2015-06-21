#include <iostream>
#include <algorithm>
#include <complex>
#include <cstdio>
#define EPS 1e-10
#define EQ(a,b) (abs(a - b) < EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))
using namespace std;

typedef complex<double> P;

double cross (P a, P b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

int is_intersected_ls(P a1, P a2, P b1, P b2) {
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
        ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

int main ()
{
    double ax, ay, bx, by, cx, cy, dx, dy;
    while (scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy) != EOF) {
        P a = P(ax, ay);
        P b = P(bx, by);
        P c = P(cx, cy);
        P d = P(dx, dy);
        
        if (EQ(is_intersected_ls(a, c, d, b), 0.0)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}
