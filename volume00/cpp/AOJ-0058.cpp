#include <iostream>
#include <complex>
#define EPS 1e-10
#define EQ(a,b) (abs(a - b) < EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))
using namespace std;

typedef complex<double> P;

double cross (P a, P b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

double dot (P a, P b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}

bool is_intersected_ls(P a1, P a2, P b1, P b2) {
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
        ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

bool is_intersected_l(P a1, P a2, P b1, P b2) {
    return !EQ( cross(a1-a2, b1-b2), 0.0 );
}

bool is_orthogonal(P a1, P a2, P b1, P b2) {
    return EQ( dot(a1 - a2, b1 - b2), 0.0);
}

int main ()
{
    double ax, bx, cx, dx, ay, by, cy, dy;
    while (cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy) {
        if (is_orthogonal(P(ax,ay), P(bx,by), P(cx,cy), P(dx,dy)))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
