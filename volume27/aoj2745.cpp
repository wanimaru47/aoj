#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, w, c, k;
    while (cin >> r >> w >> c >> k, r || w || w || c || k) {
        int ans = ceil(double(w * c - r) / k);
        cout << (ans >= 0 ? ans : 0) << endl;
    }
    
    return 0;
}
