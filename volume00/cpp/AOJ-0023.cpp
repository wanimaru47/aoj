#include <iostream>
#include <complex>
#include <algorithm>
#define EPS 1e-10
#define EQ(a,b) ((a - b) < EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))
using namespace std;

typedef complex<double> P;

int main ()
{
    int n;
    cin >> n;

    
    while (n--) {
        double ax, ay, ar, bx, by, br;
        cin >> ax >> ay >> ar >> bx >> by >> br;
        P a = P(ax, ay);
        P b = P(bx, by);

        double d = abs(a - b);
        if (d > ar + br) {
            cout << "0" << endl;
        } else if (d + ar <  br) {
            cout << "-2" << endl;
        } else if (d + br < ar) {
            cout << "2" << endl;
        } else {
            cout  << "1" << endl;
        }
    }

    return 0;
}
