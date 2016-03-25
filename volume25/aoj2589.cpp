#include <iostream>
#include <string>
#include <cmath>
#define EPS 1e-10
using namespace std;



int main ()
{
    string dir;
    while (cin >> dir, dir != "#") {
        string ins = "" ;
        for (int i = 0; i < dir.size(); i++) {
            ins += dir[i];
            if (dir[i] == 'n') i += 4;
            else i += 3;
        }

        double res = ins[ins.size() - 1] == 'n' ? 0.0 : 90.0;
        double d = 2.0;
        for (int i = ins.size() - 2; i >= 0; i--) {
            res += (ins[i] == 'n' ? -90.0 : 90.0) / d;
            d *= 2.0;
        }

        int t = 1;
        while (abs(res) > (int)((abs(res)))) {
            res *= 2;
            t *= 2;
        }

        if (t > 1) cout << (int)(abs(res)) << "/" << t << endl;
        else cout << (int)(abs(res)) << endl;
    }

    return 0;
}
