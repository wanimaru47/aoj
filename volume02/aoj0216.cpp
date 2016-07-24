#include <bits/stdc++.h>
using namespace std;

int main() {
    int w;
    int par = 4280;
    while (cin >> w, w >= 0) {
        int payment = 1150;
        if (10 < w) payment += (min(20, w) - 10) * 125;
        if (20 < w) payment += (min(30, w) - 20) * 140;
        if (30 < w) payment += (w - 30) * 160;

        cout << par - payment << endl;
    }

    return 0;
}
