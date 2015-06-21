////////////////////
//
//
//  誤差がひどかった
//
//
//
///////////////////
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

double angle (P a, P b, P p) {
    return (acos(dot(a-p,b-p) / (abs(a-p) * abs(b-p))));
}

bool is_point_in_quadrangle (P a, P b, P c, P d, P p) {
    return (EQ(angle(a,b,p) + angle(b,c,p) + angle(c,d,p) + angle(d,a,p), 2*M_PI));
}

int main ()
{
    double ax, bx, cx, dx, ay, by, cy, dy;
    while (cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy) {
        P a1 = P(ax,ay), a2 = P(bx,by), a3 = P(ax, by), a4 = P(bx, ay);
        P b1 = P(cx,cy), b2 = P(dx,dy), b3 = P(cx, dy), b4 = P(dx, cy);
        if (is_point_in_quadrangle(a4,a1,a3,a2,b1)
            || is_point_in_quadrangle(a4,a1,a3,a2,b2)
            || is_point_in_quadrangle(a4,a1,a3,a2,b3)
            || is_point_in_quadrangle(a4,a1,a3,a2,b4)
            )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
