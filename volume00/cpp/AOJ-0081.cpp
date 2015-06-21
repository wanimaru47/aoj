#include <iostream>
#include <vector>
#include <complex>
#include <string>
#include <sstream>
#include <cstdio>
#define EPS 1e-10
#define EQ(a,b) (abs(a - b) < EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))

using namespace std;

typedef complex<double> P;

double dot (P a, P b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}

P crossNormalVector (P a, P b, P p) {
    double t = dot(b-a, p-a) / (abs(b-a) * abs(b - a));
    return a + t * (b - a);
}

P rot (P x, P p, double ang) {
    ang = ang / 180.0 * M_PI;
    double p1 = p.real() - x.real();
    double p2 = p.imag() - x.imag();
    return P( p1 * cos(ang) - p2 * sin(ang) + x.real()
             , p1 * sin(ang) + p2 * cos(ang) + x.imag() );
}

P rot_pi (P x, P p) {
    return P(((p.real() - x.real()) * -1) + x.real(), ((p.imag() - x.imag()) * -1) + x.imag());
}

int main ()
{
    string str;
    while (cin >> str) {
        double x1, y1, x2, y2, py, px;        
        stringstream ss;
        for (int i = 0; i < str.size(); i++) 
            if (str[i] == ',') str[i] = ' '; 
        ss << str;
        ss >> x1 >> y1 >> x2 >> y2 >> px >> py;
        P a = P(x1, y1), b = P(x2, y2), p = P(px, py);
        P x = crossNormalVector (a, b, p);
        P res = rot (x, p, 180.0);
        printf("%.6f %.6f\n", res.real(),res.imag());
    }

    return 0;
}
