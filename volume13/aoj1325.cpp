#include <bits/stdc++.h>
using namespace std;

int main() {
    int k; cin >> k;
    for(int i = 0; i < k; i++) {
        int n, m;
        bool flag = true;
        cin >> n >> m;
        int t = n * n + m * m;
        for(int x = -144; x < 144; x++) {
            for(int y = -144; y < 144; y++) {
                if ((abs(x) || abs(y)) && t % (x * x + y * y) == 0) {
                    if (t * (x * x + y * y) == t);
                    else if (x * x + y * y == t);
                    else flag = false;  
                }
            }
        }

        cout << (flag ? "P" : "C") << endl;
    }
    return 0;
}
