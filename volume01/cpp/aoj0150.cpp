#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> v(11111, true);
    v[0] = v[1] = false;
    for (int i = 2; i <= 10010 / 2; i++) {
        for (int j = 2; j * i <= 10010; j++) {
            v[i * j] = false;
        }
    }

    vector<pair<int,int> > d;
    for (int i = 0; i <= 10010 ; i++) {
        if (v[i] && v[i+2]) d.push_back(pair<int,int>(i, i+2));
    }

    int n;
    while (cin >> n, n) {
        auto iter = upper_bound(d.begin(), d.end(), pair<int,int>(n - 2,n - 2)) - d.begin();
        while (d[iter].second > n) iter--;
        cout << d[iter].first << ' ' << d[iter].second << endl;
    }

    return 0;
}
