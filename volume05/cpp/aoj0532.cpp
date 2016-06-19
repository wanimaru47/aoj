#include <bits/stdc++.h>
using namespace std;

int main() {
    int sh, sm, ss, gh, gm, gs;
    while (cin >> sh >> sm >> ss >> gh >> gm >> gs) {
        int stime = sh * 3600 + sm * 60 + ss;
        int gtime = gh * 3600 + gm * 60 + gs;
        int atime = gtime - stime;
        cout << atime / 3600 << " ";
        atime %= 3600;
        cout << atime / 60 << " ";
        atime %= 60;
        cout << atime << endl;
    }

    return 0;
}
