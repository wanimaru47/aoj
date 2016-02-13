#include <bits/stdc++.h>
using namespace std;

int main() {
    double r, l;
    vector<int> sum_r(4), sum_l(4);
    while (cin >> l >> r) {
        
        auto add = [](double x, vector<int> &vec) {
            if (x >= 1.1) vec[0]++;
            else if (x >= 0.6) vec[1]++;
            else if (x >= 0.2) vec[2]++;
            else vec[3]++;
        };

        add(l, sum_l);
        add(r, sum_r);

    }

    for (int i = 0; i < 4; i++) {
        cout << sum_l[i] << " " << sum_r[i] << endl;
    }

    return 0;
}
