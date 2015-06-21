#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdio>
using namespace std;

int main () {
    int n;
    while (cin >> n, n) {
        vector<vector<int> > d(n, vector<int>(n, 0));
        int x = n / 2 + 1, y = n / 2;
        d[x][y] = 1;
        int m = 1;
        while (m < n * n) {
            m++;
            int dx = (x + 1) % n, dy = (y + 1) % n;
            while (d[dx][dy] != 0) {
                dx = (dx + 1) % n;
                dy = (dy + n - 1) % n;
            }
            d[dx][dy] = m;
            x = dx;
            y = dy;
            //cout << dx << " " << dy << " " << m << endl;
        }
        for (auto i : d) {
            for (auto &j : i) {
                cout << setw(4) << j;
            }
            cout << endl;
        }
    }
    
    return 0;
}
