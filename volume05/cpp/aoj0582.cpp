#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    int count = 0;
    int a = 0, b = 0, c = 0;
    while (cin >> x >> y >> z) {
        int l = max(x, max(y, z));
        if (l >= (x + y + z - l)) break;
        vector<int> v = {x, y, z};
        sort(v.begin(), v.end());
        int rhs = v[0] * v[0] + v[1] * v[1];
        int lhs = v[2] * v[2];
        if (lhs == rhs) {
            a++;
        } else if (lhs < rhs) {
            b++;
        } else {
            c++;
        }
        count++;
    }
    cout << count << " " << a << " " << b << " " << c << endl;

    return 0;
}
