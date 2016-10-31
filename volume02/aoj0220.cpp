#include <bits/stdc++.h>
using namespace std;

int main() {
    double d;
    while (cin >> d, d >= 0.0000000) {
        int n = floor(d);
        if (n >= 1 << 8) {
            cout << "NA" << endl;
            continue;
        }

        string str;
        while (n) {
            str = (n % 2 == 0 ? "0" : "1") + str;
            n /= 2;
        }
        while (str.size() < 8) str = "0" + str;
        str += ".";

        double s = d - (double)floor(d);
        double v[] = {0.5, 0.25, 0.125, 0.0625};
        for (int i = 0; i < 4; i++) {
            if (s >= v[i]) {
                s -= v[i];
                str += "1";
            } else {
                str += "0";
            }
        }
        if (s) {
            cout << "NA" << endl;
        } else {
            cout << str << endl;
        }
    }

    return 0;
}
